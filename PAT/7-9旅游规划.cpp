#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int MAXN = 505;
const int INFINITY = 1 << 10;
int N, M, S, D;
struct T 
{
    int l, m;
};
T G[MAXN][MAXN];
int Dist[MAXN];
int Cost[MAXN];

int FindMinDist(bool collected[])
{
    int minV, minDist = INFINITY;
    for (int i = 0; i < N; ++i)
    {
        if (!collected[i] && Dist[i] < minDist)
        {
            minDist = Dist[i];
            minV = i;
        }
    }
    if (minDist < INFINITY) return minV;
    else return -1;
}

void Dijkstra(int s)
{
    bool collected[N];
    memset(collected, false, sizeof collected);
    for (int i = 0; i < N; ++i)
    {
        Dist[i] = G[s][i].l;
        Cost[i] = G[s][i].m;
    }
    collected[s] = true;
    while (true)
    {
        int v = FindMinDist(collected);
        if (v == -1) break;
        collected[v] = true;
        for (int w = 0; w < N; ++w)
        {
            if (!collected[w] && G[v][w].l < INFINITY)
            {
                if (Dist[v] + G[v][w].l < Dist[w])
                {
                    Dist[w] = Dist[v] + G[v][w].l;
                    Cost[w] = Cost[v] + G[v][w].m;
                }
                else if ((Dist[v] + G[v][w].l == Dist[w]) && (Cost[v] + G[v][w].m < Cost[w]))
                {
                    Cost[w] = Cost[v] + G[v][w].m;
                }
            }
        }
    }
}

int main() 
{
    freopen("in/7-9.in", "r", stdin);
    cin >> N >> M >> S >> D;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
        {
            G[i][j].l = INFINITY;
            G[i][j].m = INFINITY;
        }

    for (int i = 0; i < M; ++i)
    {
        int e1, e2, weight, money;
        cin >> e1 >> e2 >> weight >> money;
        G[e1][e2].l = weight;
        G[e2][e1].l = weight;
        G[e1][e2].m = money;
        G[e2][e1].m = money;
    }

    Dijkstra(S);
    cout << Dist[D] << " " << Cost[D];
    return 0;
}