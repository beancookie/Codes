#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

const int MAX_N = 1005;

int cache[MAX_N];

int main()
{
    // freopen("in/L2-008.in", "r", stdin);
    int maxA = -(1 << 30);
    int maxB = -(1 << 30);
    string str;
    getline(cin, str);
    int len = str.length();
    for (int i = 0; i < len; ++i)
    {
        int l = i-1, r = i+1;
        int cur = 0;
        while (l >= 0 && r < len)
        {
            if (str[l--] != str[r++])
                break;
            cur++;
        }
        if (cur > maxA) maxA = cur;
    }
    maxA = maxA * 2 + 1;

    for (int i = 0; i < len; ++i)
    {
        int l = i, r = i+1;
        int cur = 0;
        while (l >= 0 && r < len)
        {
            if (str[l--] != str[r++])
                break;
            cur++;
        }
        if (cur > maxB) maxB = cur;
    }
    maxB *= 2;
    cout << max(maxA, maxB);
    return 0;
}