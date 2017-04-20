# str1 = input("请输入一个名字")
# str2 = input("请输入地点")
# print("{}想去{}看看".format(str1, str2))

# n = input("请输入整数n:")
# sum = 0
# for i in range(int(n)) :
#     sum += i + 1
# print("一到n求和", sum)

# for i in range(1, 10) :
#     for j in range(1, i + 1) :
#         print("{}*{}={:2}".format(j, i, i*j), end=' ')
#     print('')

from turtle import *
color('red', 'yellow')
begin_fill()
while True :
    forward(200)
    left(170)
    if abs(pos()) < 1 :
        break
end_fill()
done()