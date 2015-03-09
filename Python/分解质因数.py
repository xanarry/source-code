n = int(input("input a number:"))
i = 2
result = str(n) + "="
while n >= i:
	if n % i == 0:
		result += str(i) + '*'
		n /= i
	else:
		i += 1
print(result[:-1])


