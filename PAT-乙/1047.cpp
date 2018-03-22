#include <iostream>
#include <string>
#include <cstdio>
#include <map>
using namespace std;

const int MAXN = 10005;

int main()
{
    // freopen("1047.in", "r", stdin);
    int n;
    cin >> n;
    map<int, int> mp;
    for (int i = 0; i < n; ++i)
    {
        string s;
        int x;
        cin >> s;
        cin >> x;
        int id, pId;
        sscanf(s.data(), "%d-%d", &id, &pId);
        if (mp.find(id) == mp.end())
            mp.insert(make_pair(id, x));
        else 
            mp[id] += x;
    }
    auto it = mp.begin();
    int max = it->first;
    it++;
    for (; it != mp.end(); ++it)
        if (it->second > mp[max])
            max = it->first;
    cout << max << " " << mp[max];
    return 0;
}