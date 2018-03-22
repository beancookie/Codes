#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    char c;
    bool flag = false;
    int cnt = 0;
    double num = 0;
    double sum = 0;
    while (cin >> c)
    {
        cnt++;
        if (c == '-')
        {
            cnt--;
            flag = true;
        }
        if (c - '0' == 2)
            num++;
    }
    sum = num/cnt;
    if (flag)
        sum *= 1.5;

    if ((c-'0') % 2 == 0)
        sum *= 2;

    sum = round(sum*10000);
    cout << sum/100 << "%" << endl; 
    return 0;
}