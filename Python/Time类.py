class Time:
	"""this is a simple time class, just for practicing"""
	def __init__(self, h, m, s):
		self._hour = h;
		self._min = m;
		self._sec = s
	def display(self):
		print "hour = ", self._hour
		print "min = ", self._min
		print "sec = ", self._sec

x = Time(11, 23, 57)
print x._hour
print x._min
print x._sec
x.display()