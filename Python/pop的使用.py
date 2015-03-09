#coding=utf-8  
test = ["xiong", "yang", "is", "19", "years", "old", "and", "he", "is", "student"]
tmp = test.pop(1)
print("%s - has been poped" % tmp)
tmp = test.pop(0)
print("%s - has been poped" % tmp)
tmp = test.pop(0)
print("%s - has been poped" % tmp)
tmp = test.pop()
print("%s - has been poped" % tmp)
#pop()中的数字指定要删除什么位置的元素，为空的话删除最后一个
#元组不能使用pop操作