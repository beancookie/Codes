#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX_N = 505;
const int INFINITY = 1 << 30;

int G[MAX_N][MAX_N];
int Data[MAX_N];
int N, M, S, D;
int Dist[MAX_N];
int Count[MAX_N];
int Path[MAX_N];
int Person[MAX_N];

int FindMinDist(bool *collected)
{
    int minDist = INFINITY;
    int minV;
    for (int v = 0; v < N; ++v)
    {
        if (!collected[v] && Dist[v] < minDist)
        {
            minDist = Dist[v];
            minV = v;
        }
    }
    if (minDist < INFINITY) return minV;
    else return -1;
}

void Dijkstra(int s)
{
    bool collected[N];
    int v, w;
    for (v = 0; v < N; ++v)
    {
        Dist[v] = G[0][v];
        collected[v] = false;
        Count[v] = 1;
        Person[v] = Data[v];
    }
    Dist[s] = 0;
    Count[s] = 1;
    Person[s] = Data[s];
    Path[s] = -1;
    collected[s] = true;
    while (true)
    {
        v = FindMinDist(collected);
        if (v == -1) break;
        collected[v] = true;
        for (w = 0; w < N; ++w)
        {
            if (!collected[w] && G[v][w] < INFINITY)
            {
                // cout << Dist[v] + G[v][w] << " " << Dist[w] << endl;
                if (Dist[v] + G[v][w] < Dist[w])
                {
                    cout << v << ":" << w << endl;
                    Dist[w] = Dist[v] + G[v][w];
                    Count[w] = Count[v];
                    Path[w] = v;
                    Person[w] += Person[v];

                }
                else if (Dist[v] + G[v][w] == Dist[w] && Person[v] + Person[w] > Person[w])
                {
                    cout << v << ":" << w << endl;
                    Count[w] += Count[v];
                    Person[w] += Person[v];
                    Path[w] = v;
                }
            }
        }
    }
}

int main()
{
    freopen("in/L2-001.in", "r", stdin);
    cin >> N >> M >> S >> D;
    
    for (int i = 0; i < N; ++i)
    {
        cin >> Data[i];
        for (int j = 0; j < N; ++j)
            G[i][j] = INFINITY;
    }    
    for (int i = 0; i < M; ++i)
    {
        int v1, v2, weight;
        cin >> v1 >> v2 >> weight;
        G[v1][v2] = weight;
        G[v2][v1] = weight;
    }
    Dijkstra(S);
    for (int i = 0; i < N; ++i)
        cout << Person[i] << " ";
    cout << endl;
    cout << Count[D] << " " << Person[D] << endl;
    stack<int> st;
    int p = D;
    while (p != -1)
    {
        st.push(p);
        p = Path[p];
    }
    bool flag = true;
    while (!st.empty())
    {
        if (flag) flag = false;
        else cout << " ";
        cout << st.top();
        st.pop();
    }
    return 0;
}