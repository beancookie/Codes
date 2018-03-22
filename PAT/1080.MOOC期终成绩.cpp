#include <iostream>
#include <cmath>
#include <map>
#include <set>
#include <string>
using namespace std;

int P, M, N;

typedef struct Node
{
    string name;
    int a, b, c, g;
} Stu;

struct Rule
{
    bool operator()(const Stu &s1, const Stu &s2)
    {
        if (s1.g > s2.g)
            return true;
        else if (s1.g == s2.g)
            return s1.name < s2.name;
        else
            return false;
    }
};

int main()
{
    // freopen("data", "r", stdin);
    cin >> P >> M >> N;
    string name;
    map<string, Stu> mp;
    set<Stu, Rule> st;
    for (int i = 0; i < P; ++i)
    {
        cin >> name;
        Stu stu;
        cin >> stu.a;
        stu.b = -1;
        stu.c = -1;
        stu.g = -1;
        stu.name = name;
        mp.insert(make_pair(name, stu));
    }

    for (int i = 0; i < M; ++i)
    {
        cin >> name;
        cin >> mp[name].b;
    }

    for (int i = 0; i < N; ++i)
    {
        cin >> name;
        cin >> mp[name].c;
        if (mp[name].b > mp[name].c)
        {
            mp[name].g = round(mp[name].b * 0.4 + mp[name].c * 0.6);
        }
        else
        {
            mp[name].g = mp[name].c;
        }
    }
    for (map<string, Stu>::iterator i = mp.begin(); i != mp.end(); ++i)
    {
        if (i->second.a >= 200 && i->second.g >= 60)
        {
            st.insert(i->second);
        }
    }
    bool flag = true;
    for (set<Stu>::iterator i = st.begin(); i != st.end(); ++i)
    {
        if (flag)
            flag = false;
        else 
            cout << endl;
        cout << i->name << " " << i->a << " " << i-> b << " " << i->c << " " << i->g;
    }
    return 0;
}