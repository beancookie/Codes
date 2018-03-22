#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 105;
const int INFINITY = 1 << 20;

int N, M;
int G[MAXN][MAXN];
int D[MAXN][MAXN];

void Floyd()
{
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            D[i][j] = G[i][j];
    
    for (int k = 0; k < N; ++k)
        for (int i = 0; i < N; ++i)
            for (int j = 0; j < N; ++j)
                if (D[i][k] + D[k][j] < D[i][j])
                    D[i][j] = D[i][k] + D[k][j];
}

int FindMaxDist(int v)
{
    int maxDist = -INFINITY;
    for (int w = 0; w < N; ++w)
        if (v != w && D[v][w] > maxDist)
            maxDist = D[v][w];
    return maxDist;
}

void FindAnimal()
{
    Floyd();
    int minDist = INFINITY;
    int animal;
    for (int i = 0; i < N; ++i)
    {
        int maxDist = FindMaxDist(i);
        if (maxDist == INFINITY)
        {
            cout << "0";
            return;
        }
        if (minDist > maxDist)
        {
            minDist = maxDist;
            animal = i + 1;
        }
    }
    cout << animal << " " << minDist;
}

int main()
{
    // freopen("in/7-8.in", "r", stdin);
    cin >> N >> M;
    for (int i = 0; i < N; ++i)
        for (int j = 0; j < N; ++j)
            G[i][j] = INFINITY;

    for (int i = 0; i < M; ++i)
    {
        int e1, e2, weight;
        cin >> e1 >> e2 >> weight;
        e1--;
        e2--;
        G[e1][e2] = weight;
        G[e2][e1] = weight;
    }
    FindAnimal();
    return 0;
}