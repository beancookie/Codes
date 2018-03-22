#include <iostream>
#include <cstring>
#include <vector>
#include <string>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    vector<string> v;
    char s[11];
    while (cin.getline(s, 11))
    {
        if (strcmp(s, ".") == 0)
            break;
        v.push_back(s);
    }
    if (v.size() >= 13)
        cout << v[1] << " and " << v[13] << " Potaty are inviting you to dinner...";
    else if (v.size() >= 1)
        cout << v[1] << " is the only one for you...";
    else
        cout << "Momo... No one is for you...";
    return 0;
}