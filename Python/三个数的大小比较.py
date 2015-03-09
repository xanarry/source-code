x, y, z = raw_input("input x, y and z: ").split(" ")
x = int(x)
y = int(y)
z = int(z)
if x < y:
	x = y
	if x < z:
		x = z
else:
	if x < z:
		x = z
print 'max(x, y, z) = ', x