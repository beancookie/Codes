#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    stack<string> sk;
    string s;
    while (cin >> s)
        sk.push(s);
    bool flag = true;
    while (!sk.empty())
    {
        if (flag)
            flag = false;
        else
            cout << " ";
        cout << sk.top();
        sk.pop();
    }
    return 0;
}