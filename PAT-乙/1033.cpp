#include <iostream>
#include <string>
#include <cstring>
using namespace std;

int main()
{
    // freopen("1033.in", "r", stdin);
    string s1, s2;
    cin >> s1 >> s2;
    bool flag = false;
    if (s1.find('+') != -1)
        flag = true;
    for (int i = 0; i < s1.length(); ++i)
        s1[i] = tolower(s1[i]);
    for (int i = 0; i < s2.length(); ++i)
    {
        if (isupper(s2[i]) && flag)
            continue;
        if (s1.find(tolower(s2[i])) != -1)
            continue;
        cout << s2[i];
    }
    return 0;
}