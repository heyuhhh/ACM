#!/usr/bin/python2

lf = [0, 6, 7]
for _ in range(1000) :
    lf.append(lf[-1] + lf[-2])

def f(x, s) :
    if x == 1 :
        return "COFFEE"[s]
    if x == 2 :
        return "CHICKEN"[s]
    if s >= lf[x-2] :
        return f(x - 1, s - lf[x - 2])
    else :
        return f(x - 2, s)

for _ in range(input()) :
    n, s = map(int, raw_input().split())
    s -= 1
    r = [f(n, t) for t in range(s, min(s + 10, lf[n]))]
    print ''.join(r)
