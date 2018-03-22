#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

char r[2][3] = {
    {'C', 'J', 'B'},
    {'J', 'B', 'C'}
};

int main()
{
    freopen("in/1018.in", "r", stdin);
    int n;
    cin >> n;
    char p1, p2;
    int a[3], b[3];
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int m1[26] = {0};
    int m2[26] = {0};
    while (n--)
    {
        cin >> p1 >> p2;
        if (p1 == p2)
        {
            a[1]++;
            b[1]++;
        } 
        else 
        {
            for (int i = 0; i < 3; ++i)
            {
                if (p1 == r[0][i])
                {
                    // p2赢
                    if (p2 != r[1][i])
                    {
                        b[0]++;
                        a[2]++;
                        m2[p2 - 'A']++;
                    }
                    // p1赢
                    else 
                    {
                        a[0]++;
                        b[2]++;
                        m1[p1 - 'A']++;
                    }
                    break;
                }
            }
        }
    }
    cout << a[0] << " " << a[1] << " " << a[2] << "\n";
    cout << b[0] << " " << b[1] << " " << b[2] << "\n";
    int ma = m1[0];
    int mb = m2[0];
    for (int i = 1; i < 26; ++i)
    {
        if (m1[i] > ma) ma = m1[i];
        if (m2[i] > mb) mb = m2[i];
    }
    for (int i = 1; i < 26; ++i)
        if (m1[i] == ma) 
        {
            cout << char(i + 'A') << " ";
            break;
        }
    for (int i = 1; i < 26; ++i)
        if (m2[i] == mb) 
        {
            cout << char(i + 'A');
            break;
        }
    return 0;
}