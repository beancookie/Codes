#include <iostream>
#include <string>
#include <cctype>
#include <cstdlib>
using namespace std;

int main()
{
    // freopen("1024.in", "r", stdin);
    string str;
    cin >> str;
    int eIndex = str.find('E');
    int fIndex;
    bool isF = false;
    fIndex = str.find_last_of('+');
    if (fIndex == -1 || fIndex == 0)
    {
        fIndex = str.find_last_of('-');
        if (fIndex != 0)
            isF = true;
    }
    int fNum = atoi(str.substr(fIndex + 1, -1).data());
    if (str[0] == '-') cout << '-';
    if (!isF)
    {
        int count = 0;
        for (int i = 1; i < eIndex; ++i)
            if (str[i] != '.')
            {
                cout << str[i];
                count++;
            }
        for (int i = 0; i < fNum - count + 1; ++i)
        {
            cout << "0";
        }
    }
    else
    {
        cout << "0.";
        for (int i = 0; i < fNum - 1; ++i)
            cout << "0";
        for (int i = 1; i < eIndex; ++i)
            if (str[i] != '.')
                cout << str[i];
    }
    return 0;
}