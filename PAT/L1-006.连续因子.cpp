#include <iostream>
#include <vector>
using namespace std;

int main()
{
    vector<int> v;
    int n;
    // cin >> n;
    n = 630;
    int t = 1;
    while (t < n)
    {
        if (n % t == 0) {
            v.push_back(t);
        }
        t++;
    }
    int begin = 1;
    int max = 1;
    for (int i = 0; i < v.size(); ++i)
    {
        cout << v[i] << endl;
        if (v[i] == v[i-1] + 1)
            max++;
    }
    cout << begin << " "  << max;
    return 0;
}