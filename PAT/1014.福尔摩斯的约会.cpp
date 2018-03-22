#include <iostream>
#include <vector>
#include <string>
#include <cctype>
#include <iomanip>
using namespace std;

string days[] = {"MON", "TUE", "WED", "THU", "FRI", "SAT", "SUN"};

int main()
{
    freopen("in/1014.in", "r", stdin);
    string a, b, c, d;
    int l1, l2, day, h, m;
    getline(cin, a);
    getline(cin, b);
    getline(cin, c);
    getline(cin, d);
    l1 = a.length() < b.length() ? a.length() : b.length();
    l2 = c.length() < d.length() ? c.length() : d.length();
    int i;
    for (i = 0; i < l1; ++i)
    {
        if (a[i] == b[i] && (a[i] >= 'A' && a[i] <= 'G'))
        {
            day = a[i] - 'A';
            break;
        }
    }
    for (; i < l1; ++i)
    {
        if (a[i] == b[i] && (isalnum(a[i]) || (a[i] >= 'A' && a[i] <= 'N')))
        {
            h = isalnum(a[i]) ? a[i] - '0' : a[i] - 'A' + 10;
            break;
        }
    }
    for (int i = 0; i < l2; ++i)
    {
        if (c[i] == d[i] && isalpha(c[i]))
        {
            m = i;
            break;
        }
    }
    cout << days[day] << " " << setw(2) << setfill('0') << h << ":" << setw(2) << setfill('0') << m;
    return 0;
}