#include <iostream>
#include <cmath>
#include <cstring>
#include <algorithm>
using namespace std;

int main()
{
    // freopen("1050.in", "r", stdin);
    int N;
    cin >> N;
    int a[N];
    for (int i = 0; i < N; ++i)
        cin >> a[i];
    sort(a, a + N, greater<int>());
    int n, m;
    for (n = sqrt(N); n > 0; --n)
    {
        m = N / n;
        if (N % m == 0) break;
    }
    int x, y, k = 0;
    int r[m][n];
    memset(r, 0, sizeof(r));
    r[x = 0][y = 0] = a[k++];
    while (k < N)
    {
        while (y + 1 < n && !r[x][y+1]) r[x][++y] = a[k++];
        while (x + 1 < m && !r[x+1][y]) r[++x][y] = a[k++];
        while (y - 1 >= 0 && !r[x][y-1]) r[x][--y] = a[k++];
        while (x - 1 >= 0 && !r[x-1][y]) r[--x][y] = a[k++];
    }
    for (int i = 0; i < m; ++i)
    {
        int j = 0;
        cout << r[i][j];
        for (j = 1; j < n; ++j)
            cout << " " << r[i][j];
        cout << "\n";
    }
    return 0;
}