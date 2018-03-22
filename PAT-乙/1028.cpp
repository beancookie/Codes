#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

struct T 
{
    char name[6];
    int y, m, d;
};

T low = {"", 1814, 9, 6};
T up = {"", 2014, 9, 6};

bool f(T a, T b)
{
    if (a.y > b.y)
        return true;
    else if (a.y == b.y)
    {
        if (a.m > b.m)
            return true;
        else if (a.m == b.m)
            return a.d >= b.d ? true : false;
        else 
            return false;
    }
    else 
        return false;
}

int main()
{
    // freopen("1028.in", "r", stdin);
    int n;
    cin >> n;
    getchar();
    T a[n];
    int count = 0;
    T old, young;
    bool isFirst = true;
    for (int i = 0; i < n; ++i)
    {
        string str;
        getline(cin, str);
        sscanf(str.data(), "%s %d/%d/%d", a[i].name, &a[i].y, &a[i].m, &a[i].d);
        // cout << a[i].name << " " << f(a[i], low) << " " << f(up, a[i]) << endl;
        if (f(a[i], low) && f(up, a[i]))
        {
            if (isFirst)
            {
                young = old = a[i];
                strcpy(old.name, a[i].name);
                strcpy(young.name, a[i].name);
                isFirst = false;
            }
            count++;
            if (f(old, a[i]))
            {
                strcpy(old.name, a[i].name);
                old = a[i];
            }
            if (f(a[i], young))
            {
                strcpy(young.name, a[i].name);
                young = a[i];
            }
        }
        else 
            continue;

    }
    cout << count << " " << old.name << " " << young.name;
    return 0;
}