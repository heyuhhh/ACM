n = int(raw_input())

input_list = list(map(int, raw_input().split()))
l = set(input_list)

c1,c2 = 1,1
found = False
while c2 <= max(l) and not found:
    if c1 in l and c2 in l:
        found = True
        break
    c1,c2 = c2, c1+c2

if found:
    m1 = input_list.index(c1)
    m2 = input_list.index(c2)

    print("{} {}".format(m1+1,m2+1))
else:
    print("impossible")

