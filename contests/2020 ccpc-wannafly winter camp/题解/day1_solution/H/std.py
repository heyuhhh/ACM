t = int(input())
for _ in range(t):
	n, k = map(int, input().split(' '))
	ans = k
	n //= k
	for i in range(2, n + 1):
		flag = 0
		for j in range(2, i):
			if i % j == 0:
				flag = 1
				break
		if flag == 0:
			ans *= i
	print(ans)