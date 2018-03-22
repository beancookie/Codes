#include <iostream>
using namespace std;

int P1, P2, T1, T2;
int N;

int main()
{
    // freopen("data", "r", stdin);
    cin >> P1 >> P2;
    T1 = P1;
    T2 = P2;
    cin >> N;
    int a, b, c, d;
    int sum = 0;
    while (N--)
    {
        cin >> a >> b >> c >> d;
        sum = a + c;
        // cout << sum << " " << b << " " << d << endl;
        if (b != d)
        {
            if (b == sum)
                P1--;
            else if (d == sum)
                P2--;
        }
        if (P1 < 0 || P2 < 0)
            break;
    }
    if (P1 < 0)
        cout << "A" << endl
             << T2 - P2;
    else
        cout << "B" << endl
             << T1 - P1;

    return 0;
}