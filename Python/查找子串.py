def find(src, pattern):
    for i in range(len(src)):#遍历原始字符串,如果当前下标指向的字符与目标匹配串的第一个字符相同则比较
        if src[i] == pattern[0] and len(src) - i >= len(pattern):#目标匹配不能比原始串常
            for j in range(len(pattern)):
                if src[i + j] != pattern[j]:
                    return -1#如果在匹配过程中遇到不同的字符,返回-1
            else:#成功遍历完整个目标匹配串,返回在原始串中的起点
                return i
    return -1#遍历完也没有找到可以匹配的串,返回-1

while True:
    src = input("input string: ")
    pattern = input("input pattern: ")
    print(find(src, pattern)) 