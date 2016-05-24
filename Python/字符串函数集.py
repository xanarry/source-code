a.capitalize()#将字符串的首字母转为大写
a.count(a)#计算子串在a中出现的次数
a.expandtabs()#替换字符串中的tab为空格
a.find(a)#找到第一次子串a出现的地方,否则返回-1
a.index(s)#找到子串首次出现的下标
a.isalnum()#检查是否都为字母或者为数字
a.isalpha()#检查是否都为字母
a.isdigit()#检查是否都为数字
a.islower()#检查是否都为小写字母
a.isspace()#检查是否都为空白
a.istitle()#检查是否每个单词的首字母是大写
a.isupper()#检查是否都为大写
a.join(j)#使用s作为分割符连接序列j中的所有字符串
a.lower()#转为小写
a.upper()#转为大写
a.strip()#清除首尾空格
a.lstrip()#清除左端空白
a.rstrip()#清除右端空白
a.replace(old, new)#替换字符串中的old为new
a.split(ptr)#按ptr分割字符串,默认以空格
a.startwith(p)#检查字符串是否以p开头
a.swapcase()#将字符串中的大小写反转
a.titile()#将字符串中的每个单词首字母大写
a.zfill(width)#字符串左边填充0到长度为width
a.format(plist)#格式化字符串
比如
r = "{0}{1}{2}".format("aaa", "bbb", "ccc")
r = "my name is {0}".format("xxxx")
r = "age = {age}, sex = {sex}".format(age = 12, sex = "f")
print("age = {age}, sex = {sex}".format(age = 12, sex = "f"))