#include <iostream>
#include <cstdio>
#include <iomanip>
using namespace std;

int main()
{
    freopen("1012.in", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    float res[5] = {0};
    bool check[5] = {false};
    int flag = 1;
    int count = 0;
    res[4] = -(1 << 30);
    for (int i = 0; i < n; ++i)
    {
        int t = a[i];
        if (t % 5 == 0 && t % 2 == 0)
        {
            check[0] = true;
            res[0] += t;
        }
        if (t % 5 == 1)
        {
            check[1] = true;
            res[1] += flag * t;
            flag = -flag;
        }
        if (t % 5 == 2)
        {
            check[2] = true;
            res[2]++;
        }
        if (t % 5 == 3)
        {
            check[3] = true;
            count++;
            res[3] += t;
        }
        if (t % 5 == 4)
            if (t > check[4])
            {
                check[4] = true;
                res[4] = t;
            }
    }
    res[3] /= count;
    bool pflag = true;
    for (int i = 0; i < 5; ++i)
    {
        if (pflag) pflag = false;
        else cout << " ";
        if (check[i])
            if (i == 3)
                printf("%.1f", res[i]);
            else 
                cout << res[i];
        else cout << "N";
    }
    return 0;
}