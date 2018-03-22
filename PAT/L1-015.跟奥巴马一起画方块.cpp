#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double n;
    char c;
    cin >> n >> c;
    for (int i = 0; i < round(n / 2); ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cout << c;
        }
        cout << endl;
    }
    return 0;
}