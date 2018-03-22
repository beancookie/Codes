#include <iostream>
#include <algorithm>
#include <string>
#include <cctype>
#include <stack>
#include <map>
using namespace std;

int main()
{
    freopen("in/7-20.in", "r", stdin);
    string str;
    map<char, int> mp;
    stack<char> st;
    mp['+'] = mp['-'] = 0;
    mp['*'] = mp['/'] = 1;
    mp['('] = mp[')'] = 2;
    getline(cin, str);
    bool flag = true;
    for (char c : str)
    {
        if (isalnum(c))
            cout << c << " ";
        else if (c == '(')
            st.push(c);
        else if (c == ')')
        {
            while (!st.empty() && st.top() != '(')
            {
                cout << st.top() << " ";
                st.pop();
            }
            if (!st.empty() && st.top() == '(')
                st.pop();
        }
        else
        {
            if (!st.empty() && mp[c] > mp[st.top()])
                st.push(c);
            else if (!st.empty() && mp[c] <= mp[st.top()])
            {
                cout << st.top() << " ";
                st.pop();
                while (!st.empty())
                {
                    if (mp[c] > mp[st.top()])
                        break;
                    if (mp[c] <= mp[st.top()])
                    {
                        cout << st.top() << " ";
                        st.pop();
                    }
                }
                st.push(c);
            }
        }
    }
    while (!st.empty())
    {
        cout << st.top() << " ";
        st.pop();
    }
    return 0;
}