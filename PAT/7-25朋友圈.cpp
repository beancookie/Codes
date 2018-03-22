#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M;

int main()
{
    // freopen("in/7-25.in", "r", stdin);
    cin >> N >> M;
    vector<vector<int> > g(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int k, e, x;
        cin >> k;
        cin >> e;
        for (int j = 1; j < k; ++j)
        {
            cin >> x;
            g[e].push_back(x);
            g[x].push_back(e);
        }
    }
    int maxNum = g[1].size();
    for (int i = 1; i < g.size(); ++i)
    {
        maxNum = max(maxNum, (int)g[i].size());
    }
    cout << maxNum + 1;
    return 0;
}