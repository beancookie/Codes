#include <iostream>
#include <stack>
#include <cstring>
using namespace std;

const int MAX_N = 1005;
const int INFINITY = 1 << 30;

int G[MAX_N][MAX_N];
bool Visited[MAX_N];
int Path[MAX_N];
int Deep = 0;

int N, M, S;

void DFS(int v)
{
    if (Visited[v]) return;
    Visited[v] = true;
    Path[Deep++] = v;
    for (int w = 1; w <= N; ++w)
        if (G[v][w] < INFINITY && !Visited[w])
            DFS(w);
    Deep--;
}

int main()
{
    freopen("in/7-33.in", "r", stdin);
    cin >> N >> M >> S;
    for (int i = 1; i <= N; ++i)
    {
        Visited[i] = false;
        Path[i] = -1;
        for (int j = 1; j <= N; ++j)
            G[i][j] = INFINITY;
    }
    for (int i = 0; i < M; ++i)
    {
        int e1, e2;
        cin >> e1 >> e2;
        G[e1][e2] = 1;
        G[e2][e1] = 1;
    }
    DFS(S);
    bool flag = true;
    stack<int> st;
    int i;
    for (i = 0; i < N; ++i)
    {
        if (Path[i] == -1)
            break;
        if (flag) flag = false;
        else cout << " ";
        cout << Path[i];
        st.push(Path[i]);
    }
    if (!st.empty()) st.pop();
    while (!st.empty())
    {
        cout << " " << st.top();
        st.pop();
    }
    if (i < N) cout << " 0";
    return 0;
}