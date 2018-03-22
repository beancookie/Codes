#include <iostream>
#include <algorithm>
#include <set>
#include <vector>
using namespace std;

int main()
{
    // freopen("in/L2-005.in", "r", stdin);
    int n, m;
    cin >> n;
    set<int> sets[n];
    for (int i = 0; i < n; ++i)
    {
        cin >> m;
        for (int j = 0; j < m; ++j)
        {
            int x;
            cin >> x;
            sets[i].insert(x);
        }
    }
    cin >> m;
    for (int i = 0; i < m; ++i)
    {
        int a, b;
        cin >> a >> b;
        a--;
        b--;
        vector<int> va;
        vector<int> vb;
        set_intersection(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), back_inserter(va));
        set_union(sets[a].begin(), sets[a].end(), sets[b].begin(), sets[b].end(), back_inserter(vb));
        printf("%.2f%%\n", (float)va.size() / vb.size() * 100);
    }
    return 0;
}