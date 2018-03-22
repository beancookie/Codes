#include <iostream>
#include <vector>
using namespace std;

int main()
{
    // freopen("1045.in", "r", stdin);
    int n;
    cin >> n;
    int a[n];
    vector<int> v;
    for (int i = 0; i < n; ++i)
        cin >> a[i];
    for (int i = 0; i < n; ++i)
    {
        bool isR = true;
        for (int j = 0; j < i; ++j)
        {
            if (a[j] > a[i])
                isR = false;
        }
        for (int j = i + 1; j < n; ++j)
        {
            if (a[j] < a[i])
                isR = false;
        }
        if (isR)
            v.push_back(a[i]);
    }
    cout << v.size() << endl;
    bool flag = true;
    for (auto it = v.begin(); it != v.end(); ++it)
    {
        if (flag) flag = false;
        else cout << " ";
        cout << *it;
    }
    return 0;
}