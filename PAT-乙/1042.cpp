#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

int main()
{
    // freopen("1042.in", "r", stdin);
    string str;
    getline(cin, str);
    int a[26];
    memset(a, 0, sizeof(a));
    for (int i = 0; i < str.length(); ++i)
        if (isalpha(str[i]))
            a[tolower(str[i]) - 'a']++;
    int max = -(1 << 30);
    for (int i = 0; i < 26; ++i)
            if (a[i] > max)
                max = a[i];
    for (int i = 0; i < 26; ++i)
        if (a[i] == max)
        {
            cout << (char)(i + 'a') << " " << a[i];
            break;
        }
    return 0;
}