#include <iostream>
#include <cstring>
#include <queue>
using namespace std;
const int MAXN = 100;
const int INFINITY = 1 << 30;
int G[MAXN][MAXN];
int Nv, Ne;
bool Visited[MAXN];

void dfs(int v)
{
    cout << v << " ";
    Visited[v] = true;
    for (int w = 0; w < Nv; ++w)
        if (G[v][w] < INFINITY && !Visited[w])
            dfs(w);
}

void bfs(int v)
{
    queue<int> q;
    cout << v << " ";
    Visited[v] = true;
    q.push(v);
    while (!q.empty())
    {
        v = q.front(); q.pop();
        if (!Visited[v])
            cout << v << " ";
        Visited[v] = true;
        for (int w = 0; w < Nv; ++w)
            if (G[v][w] < INFINITY && !Visited[w])
                q.push(w);
    }
}

int main()
{
    // freopen("in/7-6.in", "r", stdin);
    cin >> Nv >> Ne;
    for (int i = 0; i < Nv; ++i)
        for (int j = 0; j < Nv; ++j)
            G[i][j] = INFINITY;

    for (int i = 0; i < Ne; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    memset(Visited, 0, sizeof(Visited));
    for (int i = 0; i < Nv; ++i)
    {
        if (!Visited[i])
        {
            cout << "{ ";
            dfs(i);
            cout << "}\n";
        }
    }
    memset(Visited, 0, sizeof(Visited));
    for (int i = 0; i < Nv; ++i)
    {
        if (!Visited[i])
        {
            cout << "{ ";
            bfs(i);
            cout << "}\n";
        }
    }
    return 0;
}