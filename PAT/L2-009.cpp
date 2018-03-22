#include <iostream>
#include <algorithm>
#include <iomanip>
#include <cmath>
#include <ratio>
using namespace std;

int N;

const double EMP = 1e-6;

struct T
{
    int id, inCount = 0, outCount = 0;
    double inMoney = 0, outMoney = 0, result = 0;
};

bool cmp(const T &a, const T &b)
{
    if (fabs(a.result - b.result) > EMP)
        return a.result > b.result;
    else if (a.inCount == b.inCount)
        return a.inCount > b.inCount;
    else 
        return a.id > b.id;
}

int main()
{
    // freopen("in/L2-009.in", "r", stdin);
    typedef ratio<1, 100> two_third;
    typedef ratio<3, 80> one_sixth;
 
    typedef ratio_add<two_third, one_sixth> sum;    

    cin >> N;
    T a[N+1];
    for (int i = 1; i <= N; ++i)
    {
        a[i].id = i;
        int k, n;
        double p;
        cin >> k;
        double outMoney = 0;
        for (int j = 0; j < k; ++j)
        {
            cin >> n >> p;
            outMoney += p / 100;
            a[n].inCount++;
            a[n].inMoney += p / 100;
        }
        a[i].outCount += k;
        a[i].outMoney += outMoney;
    }
    for (int i = 1; i <= N; ++i)
        a[i].result = a[i].inMoney - a[i].outMoney;
    
    sort(a + 1, a + N + 1, cmp);
    for (int i = 1; i <= N; ++i)
        cout << a[i].id << " " << fixed << setprecision(2) << a[i].result << endl;
    return 0;
}