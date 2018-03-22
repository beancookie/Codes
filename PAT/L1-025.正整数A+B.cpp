#include <iostream>
#include <cstdio>
#include <cctype>
#include <cstdlib>
#include <string>
using namespace std;

#define SIZE 10000

bool check(char *s)
{
    for (int i = 0; s[i] != '\0'; ++i)
    {
        if (!isdigit(s[i]))
            return false;
    }
    return true;
}

int main()
{
    freopen("data", "r", stdin);
    char s1[SIZE], s2[SIZE];
    bool c1 = true, c2 = true;
    int a, b;
    scanf("%s %s", s1, s2);
    if (check(s1))
    {
        a = atoi(s1);
        if (a > 1000 || a < 1)
            c1 = false;
    }
    else
        c1 = false;
    if (check(s2))
    {
        b = atoi(s2);
        if (b > 1000 || b < 1)
            c2 = false;
    }
    else
        c2 = false;
    if (c1)
        printf("%d + ", a);
    else 
        printf("? + ");
    if (c2)
        printf("%d = ", b);
    else 
        printf("? = ");
    if (c1 && c2)
        printf("%d", a + b);
    else 
        printf("?");
    return 0;
}