#include <iostream>
#include <string>
#include <cstdlib>
#include <cctype>
using namespace std;

bool f(string str)
{
    int k = 0;
    int dk = 0;
    for (int i = 0; i < str.length(); ++i)
    {
        // if (!isalnum(str[i]) && str[i] != '-') return false;
        if (str[i] == '.')
        {
            k = 0;
            dk++;
        }
        else k++;
    }
    // cout << dk << " " << k << endl;
    return dk <= 1 && k <= 2;
}

int main()
{
    // freopen("1054.in", "r", stdin);
    int n;
    cin >> n;
    int count = 0;
    float sum = 0;
    for (int i = 0; i < n; ++i)
    {
        string str;
        cin >> str;
        if (f(str))
        {
            count++;
            // cout << atof(str.data()) << " "; 
            sum += atof(str.data());
        }
        else
            cout << "ERROR: " << str << " is not a legal number" << endl;
    }
    if (count != 0)
        printf("The average of %d numbers is %.2f", count, sum / count);
    else 
        printf("The average of 0 numbers is Undefined");
    return 0;
}