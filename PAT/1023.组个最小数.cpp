#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int x;
    vector<int> v;
    vector<int> r;
    for (int i = 0; i < 9; ++i)
    {
        cin >> x;
        for (int j = 0; j < x; ++j)
            v.push_back(i);
    }
    sort(v.begin(), v.end());

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
    {
        if (*i != 0)
        {
            r.push_back(x);
            v.erase(i);
            break;
        }
    }

    for (vector<int>::iterator i = v.begin(); i != v.end(); ++i)
        r.push_back(*i);

    int cnt = 1;
    int num = 0;
    for (vector<int>::reverse_iterator i = r.rbegin(); i != r.rend(); ++i)
    {
        num += cnt * *i;
        cnt *= 10;
    }
    cout << num;
    return 0;
}