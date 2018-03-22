#include <iostream>
#include <cstring>
using namespace std;

int n;

struct Node
{
    int id;
    char s[10];
    char e[10];
    int t;
};

int main()
{
    freopen("data", "r", stdin);
    char c;
    int id;
    cin >> n;
    n++;
    Node nodes[n];
    int t = (n + 1) * 2;
    while (cin >> id)
    {
        Node node;
        cin >> c;
        if (c == 'S')
        {
            cin >> node.s;
            nodes[id].id = id;
            strcpy(nodes[id].s, node.s);
        }
        else
        {
            cin >> node.e;
            nodes[id].id = id;
            strcpy(nodes[id].e, node.e);
        }
    }
    for (int i = 0; i < n; ++i)
    {
        cout << nodes[i].id << " " << nodes[i].s << " " << nodes[i].e << endl;
    }
    return 0;
}