#include <iostream>

using namespace std;

int main(void)
{
    // 加法溢出
    // unsigned int a = 0xffffffff;
    // cout << "a = " << a << endl;
    // unsigned int b = a + 1;
    // cout << "b = " << b << endl;
    // cin >> a;
    // cout << "a = " << a << endl;

    // 将输入由键盘到文件
    freopen("data", "r", stdin);
    int n, max = 0, min = 0, sum = 0;
    cin >> n;
    while (n) {
        if (n > max) max = n;
        if (n < min) min = n;
        sum += n;
        cin >> n;
    }
    cout << "max = " << max << ", min = " << min << ", max = " << max << ", sum = " << sum << endl;
    return 0;
}