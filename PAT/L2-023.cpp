#include <iostream>
#include <queue>
#include <set>
#include <cstring>
using namespace std;

const int MAX_N = 505;
const int INFINITY = 1 << 20;

struct VNode 
{
    int data, color;
};

int G[MAX_N][MAX_N];
VNode Data[MAX_N];

int V, E, K, N;

bool BFS(int v)
{
    queue<int> q;
    for (int w = 1; w <= V; ++w)
        if (G[v][w] < INFINITY)
            q.push(w);
    while (!q.empty())
    {
        if (Data[v].color == Data[q.front()].color)
            return false;
        q.pop();
    }
    return true;
}

bool Solve()
{
    for (int v = 1; v <= V; ++v)
        if (!BFS(v))
            return false;
    return true;
}


int main()
{
    freopen("in/L2-023.in", "r", stdin);
    cin >> V >> E >> K;
    for (int v = 1; v <= V; ++v)
    {
        Data[v].data = v;
        for (int w = 1; w <= V; ++w)
            G[v][w] = INFINITY;
    }
    for (int v = 0; v < E; ++v)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    
    cin >> N;
    for (int i = 0; i < N; ++i)
    {
        set<int> st;
        for (int j = 1; j <= V; ++j)
        {
            cin >> Data[j].color;
            st.insert(Data[j].color);
        }
        if (st.size() > K) cout << "No\n";
        else if (Solve()) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}