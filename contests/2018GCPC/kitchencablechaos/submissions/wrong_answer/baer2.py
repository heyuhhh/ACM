#!/bin/python2

# @EXPECTED_RESULT@ WRONG_ANSWER
#
# using dp[item][dist] = best(smallest)
# Value is the smallest number (therefor best overlap) to achieve the (unoverlapped) distance of dist
# Fail: For some settings, a larger amount of wires is needed to ensure it can be shortened enough
n, d = map(int, raw_input().split())
d -= 10 # now distance between the end points

vs = []
for _ in range(n):
	vs += [int(raw_input())]

oo = 10000

dp = []
for _ in range(n+1):
	line = [oo] * (d + 5 * (n+1) + 5)
	dp += [line]

dp[0][0] = 0

for item in range(1, n+1):
	for dist in range(len(dp[0])):
		a = dp[item-1][dist]

		if vs[item-1] <= dist and dist - 5 * (dp[item-1][dist-vs[item-1]]) <= d + 10:
			b = dp[item-1][dist-vs[item-1]] + 1
		else:
			b = oo

		dp[item][dist] = min(a, b)

best = -1
for dist in range(d, len(dp[0])):
	if dp[n][dist] < 1000:
		best = max(best, float(dist - d) / (dp[n][dist] + 1))

if best == -1:
	print("impossible")
else:
	print("%.8f" % best)
