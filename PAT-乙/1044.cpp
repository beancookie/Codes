#include <iostream>
#include <string>
#include <cstring>
#include <cstdlib>
#include <cctype>
using namespace std;

string ge[] = {"jan", "feb", "mar", "apr", "may", "jun", "jly", "aug", "sep", "oct", "nov", "dec"};
string shi[] = {"", "tam", "hel", "maa", "huh", "tou", "kes", "hei", "elo", "syy", "lok", "mer", "jou"};


int main()
{
    freopen("1044.in", "r", stdin);
    int n;
    cin >> n;
    getchar();
    for (int i = 0; i < n; ++i)
    {
        string num;
        getline(cin, num);
        if (isdigit(num[0]))
        {
            int dig = atoi(num.data());
            int r = dig / 13 * 10 + dig % 13;
            string s = to_string(r);
            if (s.length() > 1)
                cout << shi[s[1] - '1'] << " " << ge[s[0] - '0'] << endl;
            else 
                cout << ge[s[0] - '1'] << endl;
        }
        else 
        {
            if (num.length() > 3)
            {
                int sIndex = num.find(' ');
                string s1 = num.substr(0, sIndex);
                string s2 = num.substr(sIndex + 1, -1);
                int r = 0;
                for (int i = 0; i < 13; ++i)
                {
                    if (s1 == shi[i])
                        r += i * 13;
                }
                for (int i = 0; i < 12; ++i)
                    if (s2 == ge[i])
                        r += i + 1;
                cout << r << endl;
            }
            else 
            {
                if (num == "tam")
                    cout << 13;
                for (int i = 0; i < 12; ++i)
                {
                    if (num == ge[i].data())
                        cout << i;
                }
            }
        }
    }
    return 0;
}