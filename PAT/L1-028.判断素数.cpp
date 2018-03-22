#include <iostream>
#include <cmath>
using namespace std;

bool is_prime(int x)
{
    if (x < 2) return false;
    for (int i = 2; i <= sqrt(x); ++i)
        if (x % i == 0) return false;
    return true;
}

int main()
{
    // freopen("data", "r", stdin);
    int n, x;
    cin >> n;
    while (n--)
    {
        cin >> x;
        if (is_prime(x))
            cout << "Yes" << endl;
        else
            cout << "No" << endl;
    }
    return 0;
}