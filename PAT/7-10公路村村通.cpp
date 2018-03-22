#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 1005;
const int INFINITY = 1 << 20;
int N, M;
int G[MAX_N][MAX_N];

struct AdjVNode
{
    int adjV, weight;
};

int FindMinDist(int *dist)
{
    int minV;
    int minDist = INFINITY;
    for (int v = 1; v <= N; ++v)
    {
        if (dist[v] != 0 && dist[v] < minDist)
        {
            minDist = dist[v];
            minV = v;
        }
    }
    if (minDist < INFINITY) return minV;
    else return -1;
}

int Prim(vector<vector<AdjVNode> > &mst)
{
    int dist[MAX_N], totalWeight = 0;
    int parent[MAX_N], v, w;
    int vCount = 0;
    for (v = 1; v <= N; ++v)
    {
        dist[v] = G[1][v];
        parent[v] = 0;
    }
    dist[1] = 0;
    parent[1] = -1;
    vCount++;
    while (true)
    {
        v = FindMinDist(dist);
        if (v == -1) break;
        int v1 = parent[v];
        AdjVNode adjVNode;
        adjVNode.adjV = v;
        adjVNode.weight = dist[v];
        mst[v1].push_back(adjVNode);
        
        totalWeight += dist[v];
        dist[v] = 0;
        vCount++;
        for (w = 1; w <= N; ++w)
        {
            if (dist[w] != 0 && G[v][w] < INFINITY)
            {
                if (G[v][w] < dist[w])
                {
                    dist[w] = G[v][w];
                    parent[w] = v;
                }
            }
        }
    }
    if (vCount < N) totalWeight = -1;
    return totalWeight;
}

int main()
{
    freopen("in/7-10.in", "r", stdin);
    cin >> N >> M;
    vector<vector<AdjVNode> > mst(N + 1);
    for (int i = 1; i <=N; ++i)
        for (int j = 1; j <= N; ++j)
            G[i][j] = INFINITY;

    for (int i = 0; i < M; ++i)
    {
        int e1, e2, weight;
        cin >> e1 >> e2 >> weight;
        G[e1][e2] = weight;
        G[e2][e1] = weight;
    }
    cout << Prim(mst);
    
    return 0;
}