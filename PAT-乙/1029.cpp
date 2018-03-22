#include <iostream>
#include <algorithm>
#include <string>
#include <vector>
#include <cstring>
using namespace std;

int main()
{
    // freopen("1029.in", "r", stdin);
    string a, b;
    vector<char> v;
    getline(cin, a);
    getline(cin, b);
    for (int i = 0; i < a.length(); ++i)
    {
        if (b.find(a[i]) == -1)
        {
            if (find(begin(v), end(v), toupper(a[i])) == end(v))
                v.push_back(toupper(a[i]));
        }
    }
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        cout << *it;
    }
    return 0;
}