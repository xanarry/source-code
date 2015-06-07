import time;
import calendar;

localtime = time.localtime(time.time())
print (localtime)
'''
0   4位数年        2008
1   月             1到12
2   日             1到31
3   小时           0到23
4   分钟           0到60
5   秒             0到61 (60或61 是闰秒)
6   一周的第几日   0到6 (0是周一)
7   一年的第几日   1到366 (儒略历)
8   夏令时         -1, 0, 1, -1是决定是否为夏令时的旗帜
'''
print("year " + str(localtime[0]))
print("month " + str(localtime[1]))

#格式化时间输出
localtime = time.asctime(time.localtime(time.time()))
print(localtime)

#输出某个月的日历
cal = calendar.month(2015, 5)
print(cal)

#返回CPU的执行时间,可以用来判断程序的性能
print(time.clock())

#程序暂停n秒
n = 5
time.sleep(n)

print("end execute")