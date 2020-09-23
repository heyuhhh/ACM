n = int(raw_input())

new_layer = [0]
for x in map(int, raw_input().split(" ")):
	new_layer.append(x - new_layer[-1])

kmin = -min(new_layer[::2])
kmax = min(new_layer[1::2])

print(max(0, kmax-kmin+1))