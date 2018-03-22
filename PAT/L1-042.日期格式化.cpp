#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    char c;
    vector<char> v;
    while (cin >> c)
    {
        if (c != '-')
            v.push_back(c);
    }
    for (int i = 4; i < v.size(); ++i)
        cout << v[i];
    cout << "-";
    for (int i = 0; i < 2; ++i)
        cout << v[i];
    cout << "-";
    for (int i = 2; i < 4; ++i)
        cout << v[i];

    return 0;
}