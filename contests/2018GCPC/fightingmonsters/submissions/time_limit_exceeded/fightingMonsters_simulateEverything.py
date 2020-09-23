def simulateFight(monster1, monster2):
    if monster1 == 0:
        return (monster1, monster2)
    else:
        return simulateFight(max(0,monster2-monster1), monster1)

n = int(raw_input())
l = list(map(int, raw_input().split()))

found = False
m1 = -1
m2 = -1
for i in range(n):
    for j in range(n):
        if i != j:
            if simulateFight(l[i], l[j]) == (0,1):
                m1 = i
                m2 = j
                found = True
                break
    if found: break

if found:
    print("{} {}".format(m1+1,m2+1))
else:
    print("impossible")
