#!/bin/python2

n, d = map(int, raw_input().split())
d -= 10 # now distance between the end points

vs = []
for _ in range(n):
	vs += [int(raw_input())]

dp = []
for _ in range(n+1):
	x = []
	for _2 in range(n+1):
		line = [0] * (d + 5 * (n+1) + 5)
		x += [line]
	dp += [x]

for itemCount in range(n+1):
	for dist in range(len(dp[0][0])):
		dp[0][itemCount][dist] = False
dp[0][0][0] = True

for item in range(1, n+1):
	for itemCount in range(n+1):
		for dist in range(len(dp[0][0])):
			a = dp[item-1][itemCount][dist]
			if dist <= d + 5 * (itemCount+1) and itemCount > 0 and vs[item-1] <= dist:
				b = dp[item-1][itemCount-1][dist-vs[item-1]]
			else:
				b = False

			dp[item][itemCount][dist] = a or b

def unwrap(item, count, dist):
	if count == 0:
		return []
	if dp[item-1][count][dist]:
		return unwrap(item-1, count, dist)
	else:
		return unwrap(item-1, count-1, dist-vs[item-1]) + [vs[item-1]]

best = -1
res = []
for dist in range(d, len(dp[0][0])):
	for count in range(n+1):
		if dp[n][count][dist]:
			val = float(dist - d) / (count + 1)
			best = max(best, float(dist - d) / (count + 1))
			res += [(val, unwrap(n, count, dist))]

if best == -1:
	print("impossible")
else:
	print("%.8f" % best)

#print("\n".join([str(x) for x in  sorted(res)]))
