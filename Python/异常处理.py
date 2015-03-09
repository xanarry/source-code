#coding=utf-8
content = {"conputer" : "Lenovo", "cellphone" : "huawei", "laptop" : "ThinkPad", "book" : "introduction to python"}
phone = raw_input("what cellphone you wanna find: ")
if content["cellphone"] == phone:
	print "yes we have a cellphone named \"%s\"" % phone
else:
	print "so sorry, we can not find any thing"

kind = raw_input("so, the next input what kind of you wanna to seach: ")
obj = raw_input("input your find object: ")
try:
	if content[kind] == obj:
		print "all right, we find it"
	else:
		print "can find nothing"
except KeyError:
	#pass#如果使用pass这可以直接忽略这种异常，如果错误不严重的话
	print "we have not catigary named ", kind, "please check"