#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main()
{
    // freopen("data", "r", stdin);
    int n;
    char c;
    char s[1001];
    cin >> n;
    vector<list<char> > v;
    cin.getline(s, 1001);
    cin.getline(s, 1001);
    for (int i = 0; i < n; ++i)
    {
        list<char> ls;
        v.push_back(ls);
    }
    for (int i = 0; s[i] != '\0';)
    {
        for (int j = 0; j < n; ++j)
        {
            if (s[i] != '\0')
            {
                v[j].push_front(s[i]);
                ++i;
            }
            else
            {
                v[j].push_front(' ');
            }
        }
    }
    for (int i = 0; i < n; ++i)
    {
        for (list<char>::iterator j = v[i].begin(); j != v[i].end(); ++j)
            cout << *j;
        cout << endl;
    }
    return 0;
}