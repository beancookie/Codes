#include <iostream>
#include <cmath>
using namespace std;

long long f(long long x)
{
    long long result = 0;
    int cnt = 0;
    long long t = x;
    while (t)
    {
        t /= 10;
        cnt++;
    }
    while (x)
    {
        result += (x % 10) * pow(10, --cnt);
        x /= 10;
    }
    return result;
}

void print(int x)
{
    long long result = 0;
    int cnt = 0;
    long long t = x;
    while (t)
    {
        cout << t % 10;
        t /= 10;
        cnt++;
    }
}

bool isp(long long x)
{
    int a[1001] = {0};
    int cnt = 0;
    long long t = x;
    while (t)
    {
        a[cnt] = t % 10;
        t /= 10;
        cnt++;
    }
    for (int i = 0, j = --cnt; i < j; ++i, --j)
    {
        if (a[i] != a[j]) return false;
    }
    return true;
}

int main()
{
    long long x;
    int cnt = 0;
    cin >> x;
    while (!isp(x))
    {
        if (cnt >= 10) break;
        cnt++;
        long long t = f(x);
        int index = 0;
        long long tt = x;
        cout << x << " + "; 
        print(x);
        cout << " = " << x + t << endl;
        x += t;
    }
    if (cnt >= 10)
        cout << "Not found in 10 iterations.";
    else
        cout << x << " is a palindromic number.";
    return 0;
}