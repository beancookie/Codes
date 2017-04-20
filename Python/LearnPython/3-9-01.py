#coding=utf-8

# 单行注释

val = input("请输入需要转换的温度(如: 32C) :")

if val[-1] in ['c', 'C']:
    f = 1.8 * float(val[0:-1]) + 32
    print("转换后的温度为：%.2fF"%f)
elif val[-1] in ['f', 'F']:
    c = (float(val[0:-1]) - 32) / 1.8
    print("转换后的温度为：%.2fC"%c)
else:
    print("input error")