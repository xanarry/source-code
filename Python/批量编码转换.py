import os
import shutil
import chardet
import codecs

def convert(filepath, old_encode, dest_encoding):
    #copy current file as backup
    path, filename = os.path.split(filepath)
    backup_file = filepath + ".bak"
    print(old_encode, "to", dest_encoding, "  converting:", filepath)
    shutil.copy(filepath, backup_file)
    try:
        #read file from old encoding
        content = codecs.open(filepath, "r", encoding = old_encode).read()
        #print(content)
        #convert content
        codecs.open(filepath, "w", encoding = dest_encoding).write(content)
    except Exception as e:
        print("error...  ", e, " >>>file has ignored")
        #if failed to convert, recover from backup
        shutil.copy(backup_file, filepath)
    finally:
        os.remove(backup_file)

path = "E:\\temporary complie file\\book_excercise"

dest_encoding = "utf-8"
just_detect_encoding = False

for x in os.listdir(path):
    if os.path.isfile(path + "\\" + x):
        res = chardet.detect(open(path + "\\" + x, "rb").read())
        if just_detect_encoding == True:
            print(res["encoding"], x)
        elif res["encoding"] != dest_encoding:
            convert(path + "\\" + x, res["encoding"], dest_encoding)
