#include <iostream>
#include <string>
#include <set>
#include <algorithm>
using namespace std;

int main()
{
    // freopen("1039.in", "r", stdin);
    string s1, s2;
    getline(cin, s1);
    getline(cin, s2);
    int count = 0;
    for (int i = 0; i < s2.length(); ++i)
    {
        int index = s1.find_first_of(s2[i]);
        if (index != -1)
        {
            s1 = s1.substr(0, index) + s1.substr(index + 1, -1);
            count++;
        }
    }
    if (count == s2.length())
        cout << "Yes " << s1.length();
    else 
        cout << "No " << s2.length() - count;
    return 0;
}