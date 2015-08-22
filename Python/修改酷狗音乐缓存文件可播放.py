import os
import shutil

patterCache = "kgtemp"
patterLyric = "krc"
suffixLen = 36
newDir = "tempMP3"

def searchPath(dire):
    '''seal recursive function inside searchPath, ensure that most variable are locablbe'''
    #files means the number of files
    #unknown means the count of files with name's encode is not gbk, and can't output
    #only define like as follow can be modify
    print("searching...")
    res = {"lyrics": None, "caches" : None}
    def traverse(dire):
        '''recursive function with file counter and output file's path'''
        try:#give up unreadable direction
            os.chdir(dire)
        except Exception:
            return
        #traverse all files or direcions in current direction
        for x in os.listdir(dire):
            #derection then recursive search
            if os.path.isdir(x) and x != "$RECYCLE.BIN":
                    traverse(os.path.abspath(x))  
            #find kugou cache path          
            elif x[-len(patterCache) : ] == patterCache:
                if not res["caches"]:
                    res["caches"] = os.getcwd()
                else:
                    break
            #find kugou lyric path
            elif x[-len(patterLyric) : ] == patterLyric:
                if not res["lyrics"]:
                    res["lyrics"] = os.getcwd()
                else:
                    break
        os.chdir("..")
        #if has find the path of both lyric and cache, then return
        if res["lyrics"] and res["caches"]:
            return
    traverse(dire)

    print("finish searching!")
    return res

def modify(cacheDir, lyricDir):
    '''copy all cache in new direction and rename all file, set sufix as mp3'''
    #change working dir to lyric dir
    os.chdir(lyricDir)
    names = {}
    print("copy name list from lyrics")
    for x in os.listdir(): #get all lyric file name
        names[x[-suffixLen : -len(patterLyric) - 1]] = x[ : -suffixLen - 1]

    #change working dir 
    os.chdir(cacheDir)
    print("check and create new direction")
    if not os.path.exists("../" + newDir):
        os.mkdir("../" + newDir)

    print("copying...")
    for item in os.listdir():
        if not os.path.exists("../" + newDir + item):
            try:
                #copy cache to new direciont
                shutil.copy(item, "../" + newDir)
                core = item[ : -len(patterCache) - 1]
                if core in names:#rename cache if has lyric file
                    os.rename("../" + newDir + item, "../" + newDir + names[core] + ".mp3")
                else:#set sufix to mp3
                    os.rename("../" + newDir + item, "../" + newDir + core + ".mp3")
            except Exception:
                pass

def verify(dire):
    '''traverse all files in new direction to check whether has file not change its sufix'''
    print("verifying")
    os.chdir(dire)
    os.chdir("../" + newDir)
    for item in os.listdir():
        if item[-3 : ] != "mp3":
            os.rename(item, item[ : -len(patterCache) - 1] + ".mp3")

##################entry######################
loc = str(input("请输入酷狗音乐的缓存磁盘:"))
while not loc.isalpha():
    print(loc, "is not valid, input again:")
    loc = str(input("请输入酷狗音乐的缓存磁盘:"))
loc += ":\\"

res = searchPath(loc)
print("cache dir:", res["caches"])
print("lyric dir:", res["lyrics"])
modify(res["caches"], res["lyrics"])
verify(res["caches"])
os.chdir(res["caches"])
os.chdir("../" + newDir)
print("done check mp3 file in", os.getcwd())