#include <iostream>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int n;
    char s[11];
    int a, b;
    cin >> n;
    while (n--)
    {
        cin >> s >> a >> b;
        if (a > 20 || a < 15 || b > 70 || b < 50)
            cout << s << endl;
    }
    return 0;
}