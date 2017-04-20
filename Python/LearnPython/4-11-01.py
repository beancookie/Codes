# encoding=utf-8

# 字符串
print("{}{}".format("圆周率是", "3.14"))
print("{0:30}".format("ABC"))
print("{0:>30}".format("ABC"))
print("{0:*^30}".format("ABC"))
print("{0:b}b, {0:o}o, {0:d}d, {0:x}x, {0:X}X".format(123))
print("abcd   asd".strip("b"))

# 元组
a = (1, 2, 3)
print(a[0])
b1 = [1, 2, 3, 4]
b2 = [5, 6, 7]
print(b1)
print(b2)
b1.reverse()
print(b1)
print(b1.pop())

from random import *

print(random())
print(uniform(1, 10))
print(randint(1, 10))

print(choice(b1))
shuffle(b1)
print(b1)
print(sample(b1, 2))

# val = input("请输入")
# try:
#     print(30 / val)
# except ZeroDivisionError:
#     print("不能为0")

b3 = "abcdefg"
print(b3[0:-1])
print("hihao%s"%b3)