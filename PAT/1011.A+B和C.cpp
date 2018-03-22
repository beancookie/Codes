#include <iostream>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int n;
    long long a, b, c;
    cin >> n;
    for (int i = 1; i <= n; ++i)
    {
        cin >> a >> b >> c;
        cout << "Case #" << i << ": ";
        if (c - b < a)
            cout << "true" << endl;
        else
            cout << "false" << endl;
    }

    return 0;
}