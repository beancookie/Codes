#include <iostream>
using namespace std;

int arr[1001] = {0};

int main()
{
    // freopen("data", "r", stdin);
    int n, m, x;
    cin >> n;
    while (n--)
    {
        int m;
        cin >> m;
        while (m--)
        {
            cin >> x;
            arr[x]++;
        }
    }
    int max_i = -1;
    int max = -1;
    for (int i = 1; i < 1001; ++i)
    {
        if (arr[i] >= max)
        {
            max = arr[i];
            max_i = i;
        }
    }
    cout << max_i << " " << max;
    return 0;
}