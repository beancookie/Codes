#include <iostream>
#include <vector>
using namespace std;

const int MAX_N = 105;

int N, M, K;
int Enemy[MAX_N][MAX_N];
vector<int> st;

int Find(int x)
{
    if (st[x] < 0) return x;
    else return st[x] = Find(st[x]);
}

void Union(int a, int b)
{
    if (st[b] < st[a])
    {
        st[b] += st[a];
        st[a] = b;
    }
    else 
    {
        st[a] += st[b];
        st[b] = a;
    }
}

int main()
{
    // freopen("in/L2-010.in", "r", stdin);
    cin >> N >> M >> K;
    st.resize(N + 1);
    for (int i = 1; i <= N; ++i)
        st[i] = -1;
    
    for (int i = 0; i < M; ++i)
    {
        int a, b, t;
        cin >> a >> b >> t;
        if (t == 1)
        {
            int rootA = Find(a);
            int rootB = Find(b);
            if (rootA != rootB)
                Union(rootA, rootB);
        }
        else 
        {
            Enemy[a][b] = 1;
            Enemy[b][a] = 1;
        }

    }


    for (int i = 0; i < K; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a) == Find(b) && Enemy[a][b] == 0)
            cout << "No problem\n";
        else if (Find(a) != Find(b) && Enemy[a][b] == 0)
            cout << "OK\n";
        else if (Find(a) == Find(b) && Enemy[a][b] == 1)
            cout << "OK but...\n";
        else if (Enemy[a][b] == 1)
            cout << "No way\n";
    }
    return 0;
}