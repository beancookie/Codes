#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main()
{
    // freopen("1037.in", "r", stdin);
    string str1, str2;
    cin >> str1 >> str2;
    int g1, s1, k1, g2, s2, k2;
    sscanf(str1.data(), "%d.%d.%d", &g1, &s1, &k1);
    sscanf(str2.data(), "%d.%d.%d", &g2, &s2, &k2);
    int t1 = g1 * 17 * 29 + s1 * 29 + k1;
    int t2 = g2 * 17 * 29 + s2 * 29 + k2;
    int t3 = t2 - t1;
    if (t3 < 0)
    {
        cout << "-";
        t3 = -t3;
    }
    int g3 = t3 / (17 * 29);
    int s3 = (t3 -  g3 * 17 * 29) / 29;
    int k3 = t3 % 29;
    cout << g3 << "." << s3 << "." << k3;
    return 0;
}