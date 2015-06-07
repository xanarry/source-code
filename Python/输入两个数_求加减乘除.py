a, b = map(int, input().strip().split())
print ("%d+%d=%d" %(a, b, a + b)),
print (str(a) + '-' + str(b) + '=' + str(a - b))
print (repr(a) + "*" + repr(b) + "=" + repr(a * b))
print ("{0}/{1}={2}".format(a, b, a / b))