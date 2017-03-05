#include <iostream>

using namespace std;

#define MAX_SIZE 10000000

char isPrimary[MAX_SIZE + 1];

// 将素数输出到文件
int main(void)
{
    freopen("primarys", "w", stdout);
    for (int i = 2; i <= MAX_SIZE; ++i)
        isPrimary[i] = 1;
    for (int i = 2; i <= MAX_SIZE; ++i)
        if (isPrimary[i])
            for (int j = 2 * i; j <= MAX_SIZE; j += i)
                isPrimary[j] = 0;
    for (int i = 2; i <= MAX_SIZE; ++i)
        if (isPrimary[i]) {
            if (!(i % 30))
                cout << endl;
            cout << i << " ";
        }
    return 0;
}