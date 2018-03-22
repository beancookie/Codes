#include <iostream>
#include <string>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

bool cmp(const pair<string, set<int> > &a, const pair<string, set<int> > &b)
{
    if (a.second.size() != b.second.size())
        return a.second.size() > b.second.size();
    else 
        return a.first > b.first;
}

vector<pair<string, set<int> > > v;

int main()
{
    // freopen("in/L2-021.in", "r", stdin);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        cin >> v[i].first;
        int k;
        cin >> k;
        for (int j = 0; j < k; ++j)
        {
            int lab;
            cin >> lab;
            v[i].second.insert(lab);
        }
    }
    sort(v.begin(), v.end(), cmp);
    bool flag = true;
    for (int i = 0; i < 3; ++i)
    {
        if (flag) flag = false;
        else cout << " ";
        if (i < v.size())
            cout << v[i].first;
        else 
            cout << "-";
    }
    return 0;
}