#include <iostream>
#include <set>
#include <map>
using namespace std;

int main()
{
    freopen("data", "r", stdin);
    map<int, set<int>, greater<int> > mp;
    set<int> st;
    int n, x;
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        cin >> x;
        set<int> sst;
        mp.insert(make_pair(x, sst));
        while (x != 1)
        {
            if (x % 2 == 0)
                x /= 2;
            else
                x = (3 * x + 1) / 2;
            mp[x].insert(x);
            st.insert(x);
        }
    }
    bool flag = true;
    for (set<int>::iterator i = st.begin(); i != st.end(); ++i)
    {
        cout << *i << endl;
        for (map<int, set<int>, greater<int> >::iterator j = mp.begin(); j != mp.end(); ++j)
        {
            if (flag) flag = false;
            else cout << " ";
            cout << j->first;
            // for (set<int>::iterator k = j->second.begin(); k != j->second.end(); ++k)
            // {
            //     cout << *k;
            //     if (*i == *k)
            //         st.erase(k);
            // }
            if (st.empty()) return 0; 
        }
    }
    return 0;
}