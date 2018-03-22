#include <iostream>
#include <set>
using namespace std;

int main()
{
    freopen("in/L2-014.in", "r", stdin);
    int n;
    cin >> n;
    set<int> st;
    for (int i = 0; i < n; ++i)
    {
        int x;
        cin >> x;
        if (!st.empty() && x < *st.rbegin())
            st.erase(*(st.lower_bound(x)));
        st.insert(x);

        for (set<int>::iterator it = st.begin(); it != st.end(); ++it)
            cout << *it << " ";
        cout << endl;
    }
    cout << st.size();
    return 0;
}