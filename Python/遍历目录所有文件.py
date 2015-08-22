import os

def allFiles(dire):
    '''seal recursive function inside allFiles, ensure that most variable are locablbe'''
    #files means the number of files
    #unknown means the count of files with name's encode is not gbk, and can't output
    #only define like as follow can be modify
    res = {"files" : 0, "unknown" : 0}
    def traverse(dire):
        '''recursive function with file counter and output file's path'''
        try:#give up unreadable direction
            os.chdir(dire)
        except Exception:
            print("拒绝访问", os.path.abspath(dire))
            return
        #traverse all files or direcions in current direction
        for x in os.listdir(dire):
            #derection then recursive search
            if os.path.isdir(x):
                    traverse(os.path.abspath(x))  
            #file then output absolutely path directly          
            else:
                try:
                    print(os.path.abspath(x))
                    res["files"] += 1
                except Exception:
                    print("含有未知编码:", os.getcwd())
                    res["unknown"] += 1
                    pass   
        os.chdir("..")
    traverse(dire)
    return res

loc = str(input("请输入路径:"))
res = allFiles(loc + ":\\")
print(res)
