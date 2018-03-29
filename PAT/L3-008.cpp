#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 10001;
const int INFI = 65535;

vector<vector<int> > G;
bool Visited[MAX_N];

int N, M, K;

int MaxDeep, MinV;

void DFS(int v, int deep)
{
    if (Visited[v]) return;
    Visited[v] = true;
    if (deep > MaxDeep)
    {
        MaxDeep = deep;
        MinV = v;
    }
    else if (deep == MaxDeep && v < MinV)
        MinV = v;

    for (int w = 0; w < G[v].size(); ++w)
        if (!Visited[w])
            DFS(G[v][w], deep + 1);
    Visited[v] = false;
}

int main()
{
    freopen("in/L3-008.in", "r", stdin);
    cin >> N >> M >> K;
    G.resize(N + 1);
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1].push_back(v2);
        G[v2].push_back(v1);
    }
    for (int i = 0; i < K; ++i)
    {
        int x;
        cin >> x;
        MaxDeep = -1;
        MinV = N;
        DFS(x, 0);
        if (MaxDeep == 0) cout << "0\n";
        else cout << MinV << endl;
    }
    return 0;
}