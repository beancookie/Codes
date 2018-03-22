#include <iostream>
#include <list>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    char c;
    list<char> G;
    list<char> P;
    list<char> L;
    list<char> T;
    while (cin >> c)
    {
        c = toupper(c);
        if (c == 'G')
            G.push_back(c);
        else if (c == 'P')
            P.push_back(c);
        else if (c == 'L')
            L.push_back(c);
        else if (c == 'T')
            T.push_back(c);
    }
    while (!G.empty() || !P.empty() || !L.empty() || !T.empty())
    {
        if (!G.empty())
        {
            cout << G.front();
            G.pop_front();
        }

        if (!P.empty())
        {
            cout << P.front();
            P.pop_front();
        }

        if (!L.empty())
        {
            cout << L.front();
            L.pop_front();
        }

        if (!T.empty())
        {
            cout << T.front();
            T.pop_front();
        }
    }
    return 0;
}