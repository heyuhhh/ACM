from collections import defaultdict

n,m = map(int, raw_input().split(" "))

g = defaultdict(lambda : defaultdict(lambda: -1))

source = 0
sink = n+1
# Add source and sink
indeg = [0 for i in range(0, n+2)]
outdeg = [0 for i in range(0, n+2)]

for _ in range(m):
	start, end, dist = map(int, raw_input().split(" "))
	if g[start][end] == -1:
		indeg[end] += 1
		outdeg[start] += 1
	g[start][end] = max(g[start][end], dist)

for i in range(1,n+1):
	if indeg[i] == 0:
		g[source][i] = 0
		indeg[i] += 1
	if outdeg[i] == 0:
		g[i][sink] = 0
		indeg[sink] += 1

dist = [-1 for _ in range(n+2)]
dist[source] = 0
q = [source]
while q:
	current = q.pop()

	for neigh in g[current].keys():
		dist[neigh] = max(dist[neigh], dist[current] + g[current][neigh])
		indeg[neigh] -= 1

		if indeg[neigh] == 0:
			q.append(neigh)

print(dist[sink])