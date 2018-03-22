#include <iostream>
#include <string>
using namespace std;

struct T
{
    string id;
    int x;
};

int main()
{
    // freopen("1041.in", "r", stdin);
    int n;
    cin >> n;
    T a[n+1];
    for (int i = 1; i <= n; ++i)
    {
        string id;
        int index, x;
        cin >> id >> index >> x;
        a[index].id = id;
        a[index].x = x;
    }
    cin >> n;
    for (int i = 0; i < n; ++i)
    {
        int index;
        cin >> index;
        cout << a[index].id << " " << a[index].x << endl;
    }
    return 0;
}