h,w = map(int, raw_input().split(" "))

clue = [list(map(int,raw_input().split(" "))) for _ in range(h+2)]
reconstruction = [["." for _ in range(w)]for _ in range(h)]

# Starting from the left upper corner of the clue matrix
for i in range(h):
	for j in range(w):
		# If the upper left corner is > 0, there must be an X in position 0,0
		# The same applies for all following positions since the reconstruction 
		# below has already been dealt with.
		if clue[i][j] > 0: 
			reconstruction[i][j] = "X"
			# X was set in position i,j of reconstruction, which is 1 off from the clue matrix, hence
			# decrease 3x3 square to the bottom-right of current cell in clue matrix
			for a in range(3):
				for b in range(3):
					clue[i+a][j+b] -= 1

# If any cell in the remaining clue matrix is not equal to 0, we cannot find a solution
if any(clue[i][j] != 0 for i in range(h+2) for j in range(w+2)):
	print("impossible")
else:
	for i in range(h):
		print("".join(reconstruction[i]))