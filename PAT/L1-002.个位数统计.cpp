#include <iostream>
#include <map>
using namespace std;

int main()
{
    map<int, int> mp;
    char c;
    while (cin >> c)
        mp[c-'0']++;
    for (map<int, int>::iterator i = mp.begin(); i != mp.end(); ++i)
        cout << i->first << ":" << i->second << endl;
    return 0;
}