#include <iostream>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int a, b, c, d;
    cin >> a >> b;
    int m1[a][b];
    for (int i = 0; i < a; ++i)
        for (int j = 0; j < b; ++j)
            cin >> m1[i][j];

    cin >> c >> d;
    int m2[c][d];
    for (int i = 0; i < c; ++i)
        for (int j = 0; j < d; ++j)
            cin >> m2[i][j];
    if (b != c)
    {
        cout << "Error: " << b << " != " << c;
        return 0;
    }
    int m3[a][d];
    cout << a << " " << d << endl;
    for (int i = 0; i < a; ++i)
    {
        for (int j = 0; j < d; ++j)
        {
            int sum = 0;
            for (int k = 0; k < b; ++k)
            {
                sum += m1[i][k] * m2[k][j];
            }
            m3[i][j] = sum;
        }
    }
    for (int i = 0; i < a; ++i)
    {
        cout << m3[i][0];
        for (int j = 1; j < d; ++j)
            cout << " " << m3[i][j];
        cout << endl;
    }
    return 0;
}