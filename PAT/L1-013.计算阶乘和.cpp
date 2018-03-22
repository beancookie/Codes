#include <iostream>
using namespace std;

int f(int n)
{
    if (n == 1) return 1;
    return n * f(n-1);
}

int main()
{
    freopen("data", "r", stdin);
    int n;
    cin >> n;
    int sum = 0;
    for (int i = 1; i <= n; ++i)
    {
        sum += f(i);
    }
    cout << sum;
    return 0;
}