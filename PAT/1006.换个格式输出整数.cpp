#include <iostream>
using namespace std;

void f1(int n)
{
    for (int i = 1; i <= n; ++i)
        cout << i;
}
void f2(int n)
{
    for (int i = 0; i < n; ++i)
        cout << "S";
}
void f3(int n)
{
    for (int i = 0; i < n; ++i)
        cout << "B";
}

int main()
{
    int x, a, b, c;
    cin >> x;
    // x = 234;
    c = x % 10;
    b = x / 10 % 10;
    a = x / 100;
    if (a) f3(a);
    if (b) f2(b);
    if (c) f1(c);
    return 0;
}