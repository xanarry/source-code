#键必须不可变，所以可以用数，字符串或元组充当，所以用列表就不行
#每个键与值用冒号隔开（:），每对用逗号分割，整体放在花括号中（{}）,并且值可以使任意数据类型

a = dict(one=1, two=2, three=3)
b = {'one': 1, 'two': 2, 'three': 3}
c = dict(zip(['one', 'two', 'three'], [1, 2, 3]))
d = dict([('two', 2), ('one', 1), ('three', 3)])
e = dict({'three': 3, 'one': 1, 'two': 2})

print(a)
#初始化字典
dict0 = {"name":"xongyang", "sex":"F", "age":21, "addr":"chongqing"}
#向字典中插入新的元素,类似于c++的map
dict0["stunum"] = "2013023058"

print(dict0)#按定义的方式输出key-value对

#遍历输出字典,变量x所表示的是字典的key,输入value使用dict[x]
for x in dict0:
    print(x + " : " + repr(dict0[x]))

#直接访问字典中的某个值
print("name:" + dict0["name"])

#修改字典

#如果使用字典中已经存在的key,那么后面的只将会替换前面的值,这里会将年龄替换为22
dict0["age"] = 22

#添加新的键值对,值可以是任意类型
dict0["hobby"] = ["music", "programming"]
#删除条目
del dict0["name"]

dict0.clear()#删除字典中的所有条目,即设为空字典
del dict0#直接删除字典,这个东西就从世界上消失了

dict1 = {1:"one", 2:"two", 3:"three"}
dict2 = {1:"one", 2:"two", 3:"three"}

#比较两个字典是否相同
print(dict1 == dict2)

#输出字典中的键值对数量
print(len(dict1))

#得到字典的浅复制,即修改复制的字典不会影响到原有的字典
dict3 = dict1.copy()

#获取字典的所有键
keys = dict1.keys()
print(keys)
#货期字典中的所有值
values = dict1.values()
print(values)

#得到可以遍历的(键, 值) 元组数组
kv_pair = dict3.items()
print(kv_pair)
#输出list化的单项列表
print(list(kv_pair))
#遍历键值对
for x in kv_pair:
    print(str(x[0]) + "->" + str(x[1]))

#"key" in "dict name"判断是否已经包含某个键,功能和c++ map对象的count()一致
print(1 in dict3)
print(12 in dict3)

#pop()函数将会删除字典的键值对,并返回该值
t = dict3.pop(1)
print(t)
print(dict3)

#获取指定键的值,和使用[]访问一致
print(dict3[2] == dict3.get(2))
t = dict3.get(2)

print(t)

#创建迭代器访问字典,直接使用iter(dictname)将是返回键的迭代器
print('iterator output dict keys')
it = iter(dict2.keys())

for x in it:
    print(x)

print('iterator output dict values')
it = iter(dict2.values())
for x in it:
    print(x)

print('iterator output dict keys-values')
it = iter(dict2.items())
for x in it:
    print(x)

from operator import itemgetter

#定义新的字典
d = {'a':2, 'b':23, 'c':5, 'd':17, 'e':1}

#对字典按键升序排序
print("按键升序排序")
#分别获取容器,容器中单元的排序关键字,下标0,即d[0],表示键,d[1]表示值
sd = sorted(d.items(), key = lambda d:d[0])
print(sd)

#对字典按键降序序排序
print("按键降序序排序")
sd = sorted(d.items(), key = lambda d:d[0], reverse = True)
print(sd)


#对字典按值升序排序
print("按值升序排序")
sd = sorted(d.items(), key = lambda d:d[1], reverse = False)
print(sd)

#对字典按值降序排序
print("按值降序排序")
sd = sorted(d.items(), key = lambda d:d[1], reverse = True)
print(sd)


#注意:reverse的参数默认是False,即升序排序,要逆序排序请将reverse值该为True
#包括sort函数,也可以传递reverse参数设定排序方式