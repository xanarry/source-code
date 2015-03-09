import sys

def input_matrix(x, y):
	t = []
	for a in range(x):
		rows = []
		for b in range(y):
			n = int(input("input a[" + str(a + 1) + ',' + str(b + 1) + "]="))
			rows.append(n)
		t.append(rows)
	return t

def multiplay_matrix(m1, m2):
	result = []
	for i in range(len(m1)):
		rows = []
		for j in range(len(m2[0])):
			n = 0
			for k in range(len(m2)):
				n += m1[i][k] * m2[k][j]
			rows.append(n)
		result.append(rows)
	return result;

def display_matrix(m):
	for x in m:
		for y in x:
			print(y, end = " ")
		print()
	print()

x1 = int(input("input rows of m1:"))
y1 = int(input('input columns of m1:'))
m1 = input_matrix(x1, y1)

x2 = int(input("input rows of m2:"))
y2 = int(input('input columns of m2:'))
m2 = input_matrix(x2, y2)

if y1 != x2:
	print('ilegal matrix multiplay')
	sys.exit()

display_matrix(m1)
display_matrix(m2)
display_matrix(multiplay_matrix(m1, m2))