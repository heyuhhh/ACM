#!/bin/python2

n, a = map(int, raw_input().split())
ai = sorted([int(raw_input()) for i in range(n)])

s = 0
for i in range(n):
	if s + ai[i] > a:
		break
	s += ai[i]

if s + i * 10 == a:
	print a-s
else:
	print "impossible"
