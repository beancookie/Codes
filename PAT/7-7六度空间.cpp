#include <iostream>
#include <iomanip>
#include <queue>
using namespace std;

const int MAXN = 1e4;
const int INFINITY = 1 << 30;
int Nv, Ne;
int G[MAXN][MAXN];
bool Visited[MAXN];

int BFS(int v)
{
    for (int i = 1; i <= Nv; ++i)
        Visited[i] = 0;
    int count = 1, level = 0, last = v, tail;
    Visited[v] = true;
    queue<int> q;
    q.push(v);
    while (!q.empty())
    {
        v = q.front(); q.pop();
        for (int w = 1; w <= Nv; ++w)
        {
            if (G[v][w] < INFINITY && !Visited[w])
            {
                Visited[w] = 1;
                q.push(w);
                count++;
                tail = w;
            }
        }
        if (v == last)
        {
            level++;
            last = tail;
            cout << v << " " << level << " " << tail << endl;
        }
        if (level == 6) break;
    }
    return count;
}

void SDS()
{
    for (int i = 1; i <= Nv; ++i)
    {
        int count = BFS(i);
        cout << i << ": " << fixed << setprecision(2) << count * 100.0 / Nv << "%" << endl;
    }
}

int main()
{
    freopen("in/7-7.in", "r", stdin);
    cin >> Nv >> Ne;
    for (int i = 1; i <= Nv; ++i)
        for (int j = 1; j <= Nv; ++j)
            G[i][j] = INFINITY;
    for (int i = 0; i <= Ne; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    SDS();
    return 0;
}