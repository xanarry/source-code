import os

code_type = (".cpp", ".c", ".py", ".java", ".js", ".h", ".hpp")
lines = {}

def every_line(filename):
    line_count = 0
    f = open(filename, mode = "r", encoding = "utf8", errors='ignore')
    while len(f.readline()) > 0:
        line_count += 1
    return line_count;

def open_dir(path, span):
    for x in os.listdir(path):
        f = path + "\\" + x
        if x[0] != "." and os.path.isdir(f):
            #print(span+ "├─" + x)
            open_dir(f, span + "│\t")
        elif os.path.isfile(f) and os.path.splitext(x)[1] in code_type:
            temp = every_line(f)
            #print(span+ "├─" + x, temp)
            if os.path.splitext(x)[1] not in lines:
                lines[os.path.splitext(x)[1]] = temp
            else:
                lines[os.path.splitext(x)[1]] += temp

root_dir = "E:\\GitHub\\source-code"
open_dir(root_dir, "");

total = 0
for x in iter(lines.items()):
    print(x[0], ":", x[1])
    total += int(x[1])

print("total:", total)