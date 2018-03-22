#include <iostream>
#include <cstring>
using namespace std;

const int MAX_N = 1e8 + 5;

int Set[MAX_N];

int N, Q;

void Union(int r1, int r2)
{
    if (Set[r1] < Set[r2])
    {
        Set[r1] += Set[r2];
        Set[r2] = r1;
    }
    else 
    {
        Set[r2] += Set[r1];
        Set[r1] = r2;
    }
}

int Find(int x)
{
    if (Set[x] < 0) return x;
    return Set[x] = Find(Set[x]);
}

int main()
{
    // freopen("in/L2-024.in", "r", stdin);
    memset(Set, 0, sizeof Set);
    cin >> N;
    int k, x;
    int kSum = 0;
    for (int i = 0; i < N; ++i)
    {
        cin >> k;
        kSum += k;
        int t;
        cin >> t;
        Set[t] = -1;
        for (int j = 1; j < k; ++j)
        {
            cin >> x;
            Set[x] = -1;
            int r1 = Find(t);
            int r2 = Find(x);
            if (r1 != r2)
                Union(r1, r2);
        }
    }
    int personNum = 0, partNum = 0;
    for (int i = 1; i <= MAX_N - 5; ++i)
    {
        if (Set[i] != 0) personNum++;
        if (Set[i] < 0) partNum++;
    }
    cout << personNum << " " << partNum << endl;
    cin >> Q;
    for (int i = 0; i < Q; ++i)
    {
        int a, b;
        cin >> a >> b;
        if (Find(a) == Find(b)) cout << "Y\n";
        else cout << "N\n";
    }
    return 0;
}