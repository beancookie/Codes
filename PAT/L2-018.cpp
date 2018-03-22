#include <iostream>
#include <vector>
using namespace std;

struct T 
{
    float e, c;
};

int main()
{
    freopen("in/L2-018.in", "r", stdin);
    int n;
    cin >> n;
    vector<T> a(n);
    for (int i = 0; i < n; ++i)
        cin >> a[i].e >> a[i].c;
    cin >> n;
    vector<T> b(n);
    for (int i = 0; i < n; ++i)
        cin >> b[i].e >> b[i].c;
    for (auto e : a)
        cout << e.e << " " << e.c << endl;
    cout << "--------------------\n";
    for (auto e : b)
        cout << e.e << " " << e.c << endl;
    return 0;
}