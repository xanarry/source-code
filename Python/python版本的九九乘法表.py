print ("9x9 table\n"),
for i in range(1, 10, 1):
	for j in range(1, i+1, 1):
		#print("%d x %d = %d\t" % (i, j, j*i)),
		print j, 'x', i, '=', i*j, '\t',
	print("\n"),