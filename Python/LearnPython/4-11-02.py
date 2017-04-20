#encoding=utf-8

try:
    file = open("python.txt", "w")

    person = {"name":"张三", "age":18}

    file.write("1234\n")
    file.write("12345\n")
    file.write("123456\n")
    file.write("1234567\n")
    file.write("12345678\n")
finally:
    file.close()

try:
    file = open("python.txt", "r")

    # print(file.read())
    line = file.readline()
    lines = file.readlines()
    print(line)
    print(lines)
finally:
    file.close()