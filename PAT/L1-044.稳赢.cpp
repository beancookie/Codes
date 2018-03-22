#include <iostream>
#include <cstring>
using namespace std;

char* mp[2][3] = {
    {"ChuiZi", "JianDao", "Bu"},
    {"Bu", "ChuiZi", "JianDao"}
};

int main()
{
    // freopen("data", "r", stdin);
    int k, cnt;
    cnt = 0;
    cin >> k;
    ++k;
    char s[10];
    // cin.getline(s, 10);
    while (cin.getline(s, 10))
    {
        if (strcmp(s, "End") == 0)
            break;
        if (cnt++ % k == 0)
        {
            if (strcmp(s, "") != 0)
            {
                cout << s << endl;
            }
            continue;
        }
        for (int i = 0; i < 3; ++i)
        {
            if (strcmp(s, mp[0][i]) == 0)
            {
                cout << mp[1][i] << endl;
                break;
            }
        }
    }
    return 0;
}