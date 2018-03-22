#include <iostream>
#include <vector>
#include <set>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    char c;
    vector<int> v;
    set<int, greater<int> > st;
    while (cin >> c)
    {
        v.push_back(c - '0');
        st.insert(c - '0');
    }

    cout << "int[] arr = new int[]{";
    bool flag = true;
    for (set<int>::iterator i = st.begin(); i != st.end(); ++i)
    {    
        if (flag)
            flag = false;
        else
            cout << ",";
        cout << *i;
    }
    cout << "};" << endl;
    flag = true;
    cout << "int[] index = new int[]{";
    for (int i = 0; i < v.size(); ++i)
    {
        int cnt = 0;
        for (set<int>::iterator j = st.begin(); j != st.end(); ++j)
        {
            if (v[i] == *j)  
            {
                if (flag)
                    flag = false;
                else
                    cout << ",";
                cout << cnt;   
                cnt = 0;
                break;
            } 
            cnt++;
         
        }
    }
    cout << "};" << endl;
    return 0;
}