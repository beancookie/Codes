#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    // freopen("in/L2-014.in", "r", stdin);
    int n;
    vector<list<int> > v;
    cin >> n;
    int q[n];
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        q[i] = x;
    }
    int maxV = n;
    for (int i = 0; i < n; ++i)
    {
        int x = q[i];
        bool flag = false;
        for (int j = 0; j < v.size(); ++j)
        {
            if (v[j].empty() || x < v[j].back())
            {
                v[j].push_back(x);
                flag = true;
                break;
            }
        }
        if (!flag)
        {
            list<int> lt;
            lt.push_back(x);
            v.push_back(lt);
        }
        for (int j = 0; j < v.size(); ++j)
        {
            while (!v[j].empty() && v[j].front() == maxV)
            {
                v[j].pop_front();
                maxV--;
            }
        }
    }
    cout << v.size();
    return 0;
}