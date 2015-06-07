import os
path = os.getenv("PATH")
print("current path: ")
for x in path.split(";"):
    print(x)