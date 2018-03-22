#include <iostream>
using namespace std;

const int MAXN = 15;

int main()
{
    // freopen("1023.in", "r", stdin);
    int a[MAXN];
    for (int i = 0; i < 10; ++i)
        cin >> a[i];
    for (int i = 1; i < 10; ++i)
        if (a[i] != 0)
        {
            cout << i;
            a[i]--;
            break;
        }   
    for (int i = 0; i < 10; ++i)
    {
        while (a[i]--)
            cout << i;
    }
    return 0;
}