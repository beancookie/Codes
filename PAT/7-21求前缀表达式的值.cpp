#include <iostream>
#include <list>
#include <stack>
#include <cctype>
#include <cstdlib>
#include <iomanip>
using namespace std;

int main()
{
    freopen("in/7-21.in", "r", stdin);
    char c;
    list<char> lt;
    stack<float> st;
    while (cin >> c)
        lt.push_front(c);
    for (char e : lt)
    {
        if (isalnum(e))
            st.push(e - '0');
        else
        {
            float a = st.top();
            st.pop();
            float b = st.top();
            st.pop();
            switch (e)
            {
            case '+':
                st.push(a + b);
                break;
            case '-':
                st.push(a - b);
                break;
            case '*':
                st.push(a * b);
                break;
            case '/':
            {
                if (e != 0.0)
                {
                    st.push(a / b);
                    break;
                }
                else 
                {
                    cout << "ERROR";
                    return 0;
                }
            }
            }
        }
    }
    cout << fixed << setprecision(1) << st.top();
    return 0;
}