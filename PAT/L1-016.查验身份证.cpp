#include <iostream>
using namespace std;

int check[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};

int m[2][11] = {
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {1, 0, 40, 9, 8, 7, 6, 5, 4, 3, 2}};

int get_sum(char *s)
{
    long sum = 0;
    for (int i = 0; i < 17; ++i)
    {
        sum += (s[i] - '0') * check[i];
    }
    return sum % 11;
}

int main()
{
    // freopen("data", "r", stdin);
    char s[20] = {0};
    int n;
    cin >> n;
    cin.getline(s, 20);
    bool flag = true;
    while (n--)
    {
        cin.getline(s, 20);
        int sum = get_sum(s);
        if (s[17] - '0' != m[1][sum])
        {
            flag = false;
            cout << s << endl; 
        }
    }
    if (flag)
        cout << "All passed";
    return 0;
}