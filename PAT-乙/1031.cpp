#include <iostream>
#include <string>
using namespace std;

int weight[] = {7, 9, 10, 5, 8, 4, 2, 1, 6, 3, 7, 9, 10, 5, 8, 4, 2};
char M[] = {'1', '0', 'X', '9', '8', '7', '6', '5', '4', '3', '2'};
int main()
{
    // freopen("1031.in", "r", stdin);
    int n;
    cin >> n;
    bool flag = true;
    while (n--)
    {
        string str;
        cin >> str;
        int sum = 0;
        for (int i = 0; i < 17; ++i)
        {
            sum += (str[i] - '0') * weight[i];
        }
        if (str[17] != M[sum % 11])
        {
            flag = false;
            cout << str << endl;
        }
    }
    if (flag) cout << "All passed";
    return 0;
}