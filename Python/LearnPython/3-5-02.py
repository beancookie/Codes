# coding=utf-8

import turtle

def drawSnake(rad, angle, len, neckrad):
    for i in range(len):
        turtle.circle(rad, angle)
        turtle.circle(-rad, angle)
    turtle.circle(rad, angle/2)
    turtle.fd(rad)
    turtle.circle(neckrad + 1, 180)
    turtle.fd(rad * 2 / 3)

def main():
    turtle.setup(600, 600, 0, 0)
    pythonsize = 30
    turtle.pensize(pythonsize)
    turtle.pencolor("black")
    turtle.seth(40)
    drawSnake(40, 80, 10, pythonsize / 2)

main()