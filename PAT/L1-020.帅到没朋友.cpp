#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int N;

int main()
{
    // freopen("data", "r", stdin);
    cin >> N;
    vector<set<int> > v;
    int m, x;
    for (int i = 0; i < N; ++i)
    {
        set<int> st;
        v.push_back(st);
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            cin >> x;
            v[i].insert(x);
        }
    }
    cin >> N;
    vector<int> vv;
    while (N--)
    {
        cin >> x;
        vv.push_back(x);
    }
    set<int> checked;
    bool flag = true;
    bool fflag = true;
    int cnt = 0;
    for (vector<int>::iterator i = vv.begin(); i != vv.end(); ++i)
    {
        if (checked.find(*i) != checked.end())
            continue;
        checked.insert(*i);
        bool is_find = false;
        for (int j = 0; j < v.size(); ++j)
        {
            // cout << "find " << *v[j].find(x) << endl;
            if (binary_search(v[j].begin(), v[j].end(), *i) && v[j].size() > 1)
                is_find = true;
        }
        if (!is_find)
        {
            fflag = false;
            if (flag)
                flag = false;
            else
                cout << " ";
            cout << *i;
        }
    }
    if (fflag)
        cout << "No one is handsome";
    return 0;
}
