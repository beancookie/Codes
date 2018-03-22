#include <iostream>
using namespace std;

int b, n;

bool check(int y)
{
    int arr[10] = {0};
    if (y < 10)
        arr[0] += 3;
    if (y < 100)
        arr[0] += 2;
    if (y < 1000)
        arr[0] += 3;

    int cnt = 0;
    // printf("%d ", y);
    while (y)
    {
        arr[y % 10]++;
        y /= 10;
    }
    for (int i = 0; i < 10; ++i)
    {
        if (arr[i] >= 1)
            cnt++;
    }
    // printf("%d\n", cnt);
    return cnt == n;
}

int main()
{
    // freopen("data", "r", stdin);
    scanf("%d %d", &b, &n);
    int cnt = 0;
    for (int i = b + 1;; ++i)
    {
        cnt++;
        if (check(i))
        {
            printf("%d %04d", cnt, i);
            break;
        }
    }
    return 0;
}