#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

vector<int> v;

int main()
{
    // freopen("in/L2-017.in", "r", stdin);
    int n;
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        v[i] = x;
    }
    sort(v.begin(), v.end());
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < v.size() / 2; ++i)
        sum1 += v[i];
    for (int i = v.size() / 2; i < v.size(); ++i)
        sum2 += v[i];
    int size1;
    if (v.size() % 2 == 1)
        size1 = v.size() / 2 + 1;
    else 
        size1 = v.size() / 2;
    int size2 = v.size() - size1;
    cout << "Outgoing #: " << size1 << endl;
    cout << "Introverted #: " << size2 << endl;
    cout << "Diff = " << sum2 - sum1 <<endl;
    return 0;
}