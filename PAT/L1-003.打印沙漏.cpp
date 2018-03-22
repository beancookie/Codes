#include <iostream>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int n;
    char c;
    cin >> n >> c;
    int t = n;
    t--;
    int cnt = 1;

    for (int i = 3; t >= i*2; i+=2)
    {
        t -= i * 2;
        cnt++;
    }
    for (int i = 0; i < cnt; ++i)
    {
        for (int j = 0; j < i; ++j)
            cout << " ";
        for (int j = 0; j < cnt*2+1 - (i+1)*2; ++j)
            cout << c;
        cout << endl;
    }
    for (int i = cnt-2; i >= 0; --i)
    {
        for (int j = 0; j < i; ++j)
            cout << " ";

        for (int j = 0; j < cnt*2+1 - (i+1)*2; ++j)
            cout << c;
        cout << endl;

    }
    cout << t;
    return 0;
}