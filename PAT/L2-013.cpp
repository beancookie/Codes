#include <iostream>
#include <cstring>
using namespace std;
const int MAX_N = 505;
const int INFINITY = 1 << 20;
int N, M, K;

int G[MAX_N][MAX_N];
bool Removed[MAX_N];
bool Collected[MAX_N];


bool DFS(int v)
{
    if (Collected[v]) return false;
    Collected[v] = true;
    for (int w = 0; w < N; ++w)
        if (!Collected[w] && G[v][w] < INFINITY)
            DFS(w);
    return true;
}

int GetCount()
{
    memcpy(Collected, Removed, N);
    int count = 0;
    for (int v = 0; v < N; ++v)
        if (DFS(v))
            count++;
    return count;
}

int main()
{
    freopen("in/L2-013.in", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            G[i][j] = INFINITY;
    for (int i = 0; i < M; ++i)
    {
        int v1, v2;
        cin >> v1 >> v2;
        G[v1][v2] = 1;
        G[v2][v1] = 1;
    }
    
    cin >> K;
    int before = GetCount();
    for (int i = 0; i < K; ++i)
    {
        int x;
        cin >> x;
        Removed[x] = true;
        int cur = GetCount();
        if (cur > before)
            cout << "Red Alert: City " << x << " is lost!\n";
        else
            cout << "City " << x << " is lost.\n";
        
        if (cur == 0)
        {
            cout << "Game Over.";
            break;
        }
        for (int i = 0; i < N; ++i)
            G[x][i] = INFINITY;
    
        for (int i = 0; i < N; ++i)
            G[i][x] = INFINITY;
        before = cur;
    }
    return 0;
}