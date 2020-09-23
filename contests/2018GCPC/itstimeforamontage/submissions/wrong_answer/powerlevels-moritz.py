n = int(raw_input())

heroes = list(map(int, raw_input().split(" ")))
villains = list(map(int, raw_input().split(" ")))

if heroes[0] > villains[0]:
	print(0)
else:
	training = villains[0] - heroes[0]
	for i in range(1,n):
		if heroes[i]+training < villains[i]:
			training += 1
			break
	print(training)