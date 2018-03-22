#include <iostream>
#include <map>
using namespace std;

struct S
{
    long z, k;
};

int main()
{
    // freopen("data", "r", stdin);
    map<int, S> mp;
    int n;
    cin >> n;
    while (n--)
    {
        int z, s, k;
        S ss;
        cin >> ss.z >> s >> ss.k;
        mp[s] = ss;
    }
    cin >> n;
    while (n--)
    {
        int s;
        cin >> s;
        cout << mp[s].z << " " << mp[s].k << endl;
    }
    return 0;
}