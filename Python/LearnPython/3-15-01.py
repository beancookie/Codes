# encoding=utf-8
# 概率法测算圆周率

from random import random
from math import sqrt
from time import clock
DARTS = 1000000000
hits = 0
clock()
for i in range(1, DARTS):
    x, y = random(), random()
    dist = sqrt(x ** 2 + y ** 2)
    # print(dist)
    if dist <= 1.0:
        hits += 1
pi = 4.0 * (float(hits) / DARTS)
print("Pi：%.8s" % pi)
print("time %-5.5ss" % clock())