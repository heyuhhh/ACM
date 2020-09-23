n = int(raw_input())
h = map(int, raw_input().split())
v = map(int, raw_input().split())

diff = v[0] - h[0]

if diff < 0:
    print 0

else:
    for i in range(n):
        if h[i]+diff < v[i]:
            print diff+1
            break
        elif h[i]+diff > v[i]:
            print diff
            break
    else:
        print diff
