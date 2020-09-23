n = int(raw_input())

input_list = list(map(int, raw_input().split()))
l = set()

c = 0
ma = 0
for x in input_list:
    if x == 1:
        c += 1
    l.add(x)
    ma = max(ma, x)

one_count = input_list.count(1)
ma = max(l)
l = set(input_list)

if one_count >= 2:
    m1 = input_list.index(1)
    m2 = input_list[m1+1:].index(1) + m1 + 1
    print("{} {}".format(m1+1, m2+1))
else:
    c1,c2 = 1,2
    found = False
    while c2 <= ma and not found:
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
         
