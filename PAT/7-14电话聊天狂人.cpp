#include <iostream>
#include <string>
#include <unordered_map>
#include <algorithm>
using namespace std;

bool cmp(const pair<string, int> &a, const pair<string, int> &b)
{
    if (a.second != b.second)
        return a.second < b.second;
    return a.first < b.first;
}

int main()
{
    // freopen("in/7-14.in", "r", stdin);
    int n;
    unordered_map<string, int> mp;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        string a, b;
        cin >> a >> b;
        if (mp.find(a) == mp.end())
            mp.insert(make_pair(a, 1));
        else mp[a]++;

        if (mp.find(b) == mp.end())
            mp.insert(make_pair(b, 1));
        else mp[b]++;
    }
    auto max = max_element(mp.begin(), mp.end(), cmp);
    cout << max->first << " " << max->second;
    return 0;
}