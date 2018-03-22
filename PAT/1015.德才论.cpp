#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

struct Node 
{
    int id, d, c;
};

int n, l, h;

struct cmp 
{
    bool operator() (const Node &a, const Node &b)
    {
        if (a.d + a.c != b.d + b.c)
            return a.d + a.c > b.d + b.c;
        else if (a.d != b.d)
            return a.d > b.d;
        else 
            return a.id < b.id;
    }
};

int main()
{
    freopen("in/1015.in", "r", stdin);
    cin >> n >> l >> h;
    int count = n;
    Node node;
    vector<Node> v[4];
    for (int i = 0; i < n; ++i)
    {
        cin >> node.id >> node.d >> node.c;
        if (node.d < l || node.c < l)
        {
            count--;
            continue;
        }
        if (node.d >= h && node.c >= h)
            v[0].push_back(node);
        else if (node.d >= h && node.c < h)
            v[1].push_back(node);
        else if (node.d < h && node.c < h && node.d >= node.c)
            v[2].push_back(node);
        else 
            v[3].push_back(node);
    }
    cout << count << "\n";
    for (int i = 0; i < 4; ++i)
    {
        sort(v[i].begin(), v[i].end(), cmp());
        for (auto e : v[i])
            cout << e.id << " " << e.d << " " << e.c << "\n";
    }
    return 0;
}