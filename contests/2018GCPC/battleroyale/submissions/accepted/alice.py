#!/usr/bin/python
import math

eps = 10**(-15)

cur = map(float, raw_input().split())
dest = map(float, raw_input().split())
map(float, raw_input().split())
red = map(float, raw_input().split())

def dist(a, b):
    dy = a[1] - b[1]
    dx = a[0] - b[0]
    return math.sqrt(dy*dy+dx*dx)

def getPointOnRadius(mid, rad, angle):
    return mid[0] + rad * math.cos(angle), mid[1] + rad * math.sin(angle)

def findTangendPoints(outer, inner, rad):
    dy = outer[1] - inner[1]
    dx = outer[0] - inner[0]

    angle_min = math.atan2(dy, dx)
    angle_max = angle_min + math.pi

    while angle_min < 0: angle_min += 2*math.pi

    pmin = getPointOnRadius(inner, rad, angle_min)
    pmax = getPointOnRadius(inner, rad, angle_max)

    if dist(pmin, outer) > dist(pmax, outer): angle_min, angle_max = angle_max, angle_min

    expected_distance = math.sqrt(dist(outer, inner)*dist(outer, inner)-rad*rad)

    min_safe = angle_min

    while(math.fabs(angle_min - angle_max) > eps):
        newangle = (angle_min + angle_max) / 2
        midPoint = getPointOnRadius(inner, rad, newangle)
        if(dist(midPoint, outer) < expected_distance):
            angle_min = newangle
        else:
            angle_max = newangle

    return [newangle, min_safe - (newangle-min_safe)]

tang_cur_angles = findTangendPoints(cur, red[0:2], red[2])
tang_dest_angles = findTangendPoints(dest, red[0:2], red[2])

pos_dist = []

for w in tang_cur_angles:
    while w < 0: w += 2*math.pi
    for v in tang_dest_angles:
        while v < 0: v += 2*math.pi
        shot_angle = min(math.fabs(w - v), 2*math.pi - math.fabs(w - v))
        pos_dist.append(dist(cur, getPointOnRadius(red[0:2], red[2], w)) + dist(dest, getPointOnRadius(red[0:2], red[2], v)) + (shot_angle * red[2]))

print(min(pos_dist))
