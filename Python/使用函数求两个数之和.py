def add(a, b ):
	'''This is a function to add two object and return the rusult!'''
	return a + b
x, y = raw_input("input a and b: ").split(" ")
print add.__doc__
try:
	print x, '+', y, '=', add(float(x), float(y))
except ValueError:
	print "please check you input type"