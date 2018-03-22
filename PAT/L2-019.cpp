#include <iostream>
#include <string>
#include <vector>
#include <set>
using namespace std;

struct T 
{
    string id;
    int num;
};

vector<T> v;

int main()
{
    // freopen("in/L2-019.in", "r", stdin);
    int n, m;
    cin >> n;
    set<string> floors;
    float sum = 0;
    for (int i = 0; i < n; ++i)
    {
        string id;
        cin >> id;
        floors.insert(id);
    }
    cin >> m;
    v.resize(m);
    for (int i = 0; i < m; ++i)
    {
        cin >> v[i].id >> v[i].num;
        sum += v[i].num;
    }
    sum /= m;
    set<string> result;
    for (auto e : v)
        if (e.num > sum)
            result.insert(e.id);
    bool flag = true;
    for (auto e : result)
        if (floors.find(e) == floors.end())
        {
            flag = false;
            cout << e << endl;
        }
    if (flag) cout << "Bing Mei You";
    return 0;
}