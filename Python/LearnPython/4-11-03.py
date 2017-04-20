# encoding=utf-8

import turtle

def drawline(t, x1, y1, x2, y2):
    t.penup()
    t.goto(x1, y1)
    t.pendown()
    t.goto(x2, y2)

def main():
    turtle.setup(800, 600, 0, 0)

if __name__ == "__main__":
    main()
