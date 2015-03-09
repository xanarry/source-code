#coding=utf-8
x = input("input a numbre: ")
x = int(x)
flag = 0
'''
for num in (0, 1, 2, 3, 4, 5, 6, 7, 8, 9):
	if num == x:
		flag = 1
		break #break终止整个循环
if flag == 1:
	print x, "is in num",
else:
	print x, "is not in num",

'''
for num in (0, 1, 2, 3, 4, 5, 6, 7, 8, 9):
	if num == x:
		continue#continue跳过continue之后的循环语句，
	print num