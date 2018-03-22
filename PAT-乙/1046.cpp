#include <iostream>
using namespace std;

int main()
{
    // freopen("1046.in", "r", stdin);
    int n;
    cin >> n;
    int sumA = 0, sumB = 0;
    for (int i = 0; i < n; ++i)
    {
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        bool aw = false, bw = false;
        if (b == a + c) aw = true;
        if (d == a + c) bw = true;
        if (aw && !bw) sumA++;
        else if (bw && !aw) sumB++;
    }
    cout << sumB << " " << sumA;
    return 0;
}