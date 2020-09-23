import fractions
import sys

def isPrime(x):
    i = 2
    while i * i <= x:
        if not (x % i): return False
        i = i + 1
    return x != 1

n = int(raw_input())

for i in xrange(n):
    a, b = map(fractions.Fraction, raw_input().split())

    c = a / b;
    d, e = c.numerator, c.denominator

    if d == 1 and e == 1:
        print("2 2")
    elif isPrime(d) and isPrime(e):
        print("{} {}".format(d, e))
    else:
        print("impossible")
