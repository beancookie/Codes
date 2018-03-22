#include <iostream>
#include <string>
#include <queue>
using namespace std;

struct T
{
    string msg;
    int x;
    bool operator<(const T &b) const
    {
        return x > b.x;
    }
};

int main()
{
    // freopen("in/7-26.in", "r", stdin);
    int n;
    cin >> n;
    priority_queue<T> q;
    for (int i = 0; i < n; ++i)
    {
        string op;
        cin >> op;
        if (op[0] == 'P')
        {
            T t;
            cin >> t.msg >> t.x;
            q.push(t);
        }
        else
        {
            if (!q.empty())
            {
                cout << q.top().msg << endl;
                q.pop();
            }
            else 
            {
                cout << "EMPTY QUEUE!\n";
            }
        }
    }
    return 0;
}