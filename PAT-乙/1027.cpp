#include <iostream>
using namespace std;

int main()
{
    freopen("1027.in", "r", stdin);
    int n;
    char c;
    cin >> n >> c;
    int sum = 1;
    int k = 2;
    while (sum <= n)
    {
        sum += (k * 2 - 1) * 2;
        if (sum > n)
        {
            sum -= (k * 2 - 1) * 2;
            k--;
            break;
        }
        k++;
    }
    int t = k * 2 - 1;
    for (int i = 0; i < k; ++i)
    {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = 0; j < t; ++j)
            cout << c;
        t -= 2;
        cout << "\n";
    }
    t = 3;
    for (int i = 0; i < k - 1; ++i)
    {
        for (int j = k - i - 2; j > 0; --j)
            cout << " ";
        for (int j = 0; j < t; ++j)
            cout << c;
        t += 2;
        cout << "\n";
    }
    cout << n - sum;
    return 0;
}