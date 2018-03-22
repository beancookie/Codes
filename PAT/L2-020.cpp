#include <iostream>
using namespace std;

int main()
{
    freopen("in/L2-020.in", "r", stdin);
    int n;
    double z, r;
    cin >> n >> z >> r;
    double sum = 0;
    for (int i = 0; i < n; ++i)
    {
        int nk, x;
        cin >> nk;
        if (nk == 0) 
        {
            cin >> x;
            z *= x;
            // sum += z;
        }
        else 
        {
            for (int j = 0; j < nk; ++j)
                cin >> x;
            z *= (1.0 - (r / 100.0));
        }
        cout << z << endl;
    }
    cout << sum;

    return 0;
}