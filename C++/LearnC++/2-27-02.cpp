#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int a = 3, b = 4;
    double d1 = 23.34;
    unsigned long l1 = 34; 
    printf("I have %d\n", a);
    printf("I have a\nbook");
    printf("a+b = %d\n", a+b);
    printf("a+b = %05d\n", a+b);
    printf("d1 = %6.5f\n", d1);
    printf("l1 = %lu\n", l1);
    return 0;
}