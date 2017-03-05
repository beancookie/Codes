#include <iostream>
using namespace std;

#define EPS 0.000000000001

int main(void)
{
    // 牛顿迭代法求平方根
    freopen("data", "r", stdin);
    int n = 17;
    cout << "input = " << n << endl;
    if (n >= 0) {
        double x = n / 2, lastX = x + 1 + EPS; // 确保能够进行一次迭代
        int count = 0;
        while (x - lastX > EPS || lastX - x > EPS) { // 精度未达要求继续迭代
            cout << ++count << ",";
            lastX = x;
            x = (x + n / x) / 2;
        }
        cout << endl << x << endl;
        cout << x * x;
    } else
        cout << "It can not be nagitive";
    return 0;
}