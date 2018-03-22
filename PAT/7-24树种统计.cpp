#include <iostream>
#include <string>
#include <map>
#include <cstdio>
using namespace std;

int main()
{
    // freopen("in/7-24.in", "r", stdin);
    int n;
    string str;
    map<string, int> mp;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        getline(cin, str);
        if (mp.find(str) != mp.end())
            mp[str]++;
        else
            mp.insert(make_pair(str, 1));
    }
    for (auto e : mp)
        printf("%s %.4f%%\n", e.first.c_str(), e.second * 100.0 / n);
    return 0;
}