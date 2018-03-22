#include <iostream>
#include <queue>
using namespace std;

#define MAX_SIZE 11
#define INIF 65535

int G[MAX_SIZE][MAX_SIZE];
bool visited[MAX_SIZE];
int n, e;

void init()
{
    for (int i = 0; i < n; ++i)
        visited[i] = false;
}

void dfs(int v)
{
    visited[v] = true;
    cout << v << " ";
    for (int w = 0; w < n; ++w)
    {
        if (G[v][w] < INIF && !visited[w])
            dfs(w);
    }
}

void bfs(int v)
{
    queue<int> q;
    q.push(v);
    visited[v] = true;
    while (!q.empty())
    {
        v = q.front();
        q.pop();
        cout << v << " ";
        for (int w = 0; w < n; ++w)
        {
            if (G[v][w] < INIF && !visited[w])
            {
                q.push(w);
                visited[w] = true;
            }
        }
    }
}

void list1()
{
    init();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            cout << "{ ";
            dfs(i);
            cout << "}";
            cout << endl;
        }
    }
}

void list2()
{
    init();
    for (int i = 0; i < n; ++i)
    {
        if (!visited[i])
        {
            cout << "{ ";
            bfs(i);
            cout << "}";
            cout << endl;
        }
    }
}

int main()
{
    freopen("data", "r", stdin);
    cin >> n >> e;
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            G[i][j] = INIF;
        }
    }
    init();
    for (int i = 0; i < e; ++i)
    {
        int v, w;
        cin >> v >> w;
        G[v][w] = 1;
        G[w][v] = 1;
    }
    list1();
    list2();
    return 0;
}