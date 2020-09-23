from fractions import gcd
from decimal import Decimal

def isPrime(x):
	if x < 2:
		return False

	i = 2
	while i**2 <= x:
		if x % i == 0: return False
		i += 1
	return True

for _ in range(int(raw_input())):
	a,b = map(lambda x: int(float(x) * 10e5), raw_input().split(" "))

	g = gcd(a,b)
	a /= g
	b /= g

	if a == b:
		print("2 2")
	elif isPrime(a) and isPrime(b):
		print("{} {}".format(a,b))
	else:
		print("impossible")



