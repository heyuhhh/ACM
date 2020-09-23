from math import sqrt

# Wrong answer that does not handle the case where x = 1

x = int(raw_input())

n = 3
found = False
while 2**(n-1) < x and not found:
	current_sum = 1
	k = 1
	while current_sum < x:
		k += 1
		current_sum += k**(n-1)
	if current_sum == x:
		found = True
		print n, k
		break
	n += 1

if not found: print("impossible")
