#include <iostream>
#include <string>
using namespace std;

int main()
{
    // freopen("in/1016.in", "r", stdin);
    string s1, s2;
    int a, b;
    cin >> s1 >> a >> s2 >> b;
    int sum1 = 0, sum2 = 0;
    for (int i = 0; i < s1.length(); ++i)
        if (s1[i] - '0' == a)
            sum1 = sum1 * 10 + (s1[i] - '0');
    for (int i = 0; i < s2.length(); ++i)
        if (s2[i] - '0' == b)
            sum2 = sum2 * 10 + (s2[i] - '0');
    cout << sum1 + sum2;
    return 0;
}