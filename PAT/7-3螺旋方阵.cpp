#include <stdio.h>

#define MAX_SIZE 1001
int v[MAX_SIZE][MAX_SIZE];

int main()
{
    int n;
    // n = 5;
    // cin >> n;
    scanf("%d", &n);
    int r, c;
    if (n % 2 == 0)
        r = n / 2;
    else
        r = n / 2 + 1;
    c = n;
    int cnt = 1;
    for (int i = 0; i < c; ++i)
    {
        for (int j = i; j < c - i; ++j)
        {
            // cout << "[" << i << "]" << "[" << j << "]";
            v[i][j] = cnt++;
            // cout << cnt++ << " ";
        }
        // cout << endl;
        for (int j = i + 1; j < c - i; ++j)
        {
            // cout << "[" << j << "]" << "[" << c - i - 1 << "]";
            v[j][c-i-1] = cnt++;
            // cout << cnt++ << " ";
        }
        // cout << endl;
        for (int j = c - i - 1; j > i; --j)
        {
            // cout << "[" << c - i - 1 << "]" << "[" << j - 1 << "]";
            v[c-i-1][j-1] = cnt++;
            // cout << cnt++ << " ";
        }
        // cout << endl;
        for (int j = c - i - 1; j > i + 1; --j)
        {
            // cout << "[" << j - 1 << "]" << "[" << i << "]";
            v[j-1][i] = cnt++;
            // cout << cnt++ << " ";
        }
        // cout << endl;
        // break;
    }
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
            printf("%3d", v[i][j]);
        printf("\n");
    }
    return 0;
}