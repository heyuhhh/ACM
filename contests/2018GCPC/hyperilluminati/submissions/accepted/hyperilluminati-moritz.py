from math import sqrt

x = int(raw_input())

n = 3
if x == 1:
	print 3, 1
	exit()
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
