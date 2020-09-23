from collections import defaultdict

def get_connection(p, d):
	return pieces[p][(d + pieces[p][-1]) % 4] 

def rotate_piece(p):
	pieces[p][-1] = (pieces[p][-1]+1)%4

def rotate_connection_(p,c,d):
	for i in range(4):
		if get_connection(p,i+d) == c:
			pieces[p][-1] = (pieces[p][-1]+i)%4

def get_fitting_piece(p, d):
	idx_list = connections[get_connection(p, d)]
	if idx_list[0] == p:
		return idx_list[1]
	else:
		return idx_list[0]

north = 0
west = 1
south = 2
east = 3

n = int(raw_input())
connections = defaultdict(list)

pieces = []
corner = -1
error = False

for i in range(n):
	c = 0
	p = list(map(int, raw_input().split(" ")))
	for j in range(4):
		connections[p[j]].append(i)
		
		if p[j] == 0 and p[(j+1)%4] == 0:
			corner = i
			
	# add current rotation
	p.append(0)
	pieces.append(p)

if corner == -1:
	print("impossible")
	exit(0)

used = [False for _ in range(len(pieces))]
current_piece = corner

while get_connection(current_piece, north) != 0 or get_connection(current_piece, west) != 0:
	rotate_piece(current_piece)

solved = []
solved.append([])
solved[-1].append(current_piece)
used[current_piece] = True

pos = 0

for _ in range(n-1):
	if get_connection(current_piece, east) == 0:

		idx = get_fitting_piece(solved[-1][0], south)
		if used[idx] or current_piece == idx:
			error = True
			break

		# rotate piece
		while get_connection(idx, north) != get_connection(solved[-1][0], south):
			rotate_piece(idx)

		if get_connection(idx, west) != 0:
			error = True
			break

		solved.append([])
		solved[-1].append(idx)
		current_piece = idx
		used[idx] = True
		pos = 1
	else:
		idx = get_fitting_piece(current_piece, east)

		if used[idx] or idx == current_piece:
			error = True
			break

		while get_connection(idx, west) != get_connection(current_piece, east):
			rotate_piece(idx)

		if len(solved) > 1 and (len(solved[-2]) <= pos or get_connection(idx, north) != get_connection(solved[-2][pos], south) or get_connection(idx, north) == 0):
			#print("Top does not fit!")
			error = True
			break

		solved[-1].append(idx)
		current_piece = idx
		used[idx] = True
		pos += 1

test_len = len(solved[0])
for l in solved:
	if len(l) != test_len:
		error = True

if error: 
	print("impossible")
else:
	print ("{} {}".format(len(solved), len(solved[0])))
	for i in range(len(solved)):
		res = []
		for j in range(len(solved[i])):
			res.append(str(1+solved[i][j]))
		print(" ".join(res))