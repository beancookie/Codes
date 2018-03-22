#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    freopen("data", "r", stdin);
    double emp;
    cin >> emp;
    int t = 1;
    int tag = 1;
    double sum = 0;
    while (fabs(1.0 / t) > emp)
    {
        sum += 1.0 / t * tag;
        cout << t << " " << tag << " " << sum << endl;
        tag = -tag;
        t += 3;
    }
    cout << sum;
    return 0;
}