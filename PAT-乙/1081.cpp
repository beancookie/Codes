#include <iostream>
#include <string>
#include <cctype>
using namespace std;

bool f1(string str)
{
    for (int i = 0; i < str.size(); ++i)
        if (!isalpha(str[i]) && !isdigit(str[i]) && str[i] != '.')
            return true;
    return false;
}

bool f2(string str)
{
    bool a = false, b = false;
    for (int i = 0; i < str.size(); ++i)
        if (isalpha(str[i]))
            a = true;
        else if (isdigit(str[i]))
            b = true;
    return a && !b;
}


bool f3(string str)
{
    bool a = false, b = false;
    for (int i = 0; i < str.size(); ++i)
        if (isalpha(str[i]))
            a = true;
        else if (isdigit(str[i]))
            b = true;
    return !a && b;
}

int main()
{
    // freopen("1081.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (str.size() < 6) cout << "Your password is tai duan le.\n";
        else if (f1(str)) cout << "Your password is tai luan le.\n";
        else if (f2(str)) cout << "Your password needs shu zi.\n";
        else if (f3(str)) cout << "Your password needs zi mu.\n";
        else cout << "Your password is wan mei.\n";
    }
    return 0;
}