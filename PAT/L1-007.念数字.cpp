#include <iostream>
#include <vector>
#include <string>
using namespace std;

string s[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    vector<int> v;
    int n, flag = 0, k = 1;
    cin >> n;
    if (n == 0)
    {
        cout << "ling";
        return 0;
    }
    if (n < 0)
    {
        n = -n;
        flag = 1;
    }
    while (n)
    {
        v.push_back(n % 10);
        n /= 10;
    }
    if (flag)
        cout << "fu ";
    for (int i = v.size() - 1; i >= 0; --i)
    {
        if (k)
            k = 0;
        else
            cout << " ";
        cout << s[v[i]];
    }
    return 0;
}