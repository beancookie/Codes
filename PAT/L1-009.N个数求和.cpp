#include <iostream>
#include <vector>
#include <map>
using namespace std;

struct Node 
{
    int x, y;
};

Node add(Node a, Node b)
{
    Node r;
    r.y = a.y * b.y;
    r.x = a.x * b.y + b.x * a.y;
    return r; 
}

void f(Node &node)
{
    int a = node.x;
    int b = node.y;
    int k = a % b;
    while (k)
    {
        a = b;
        b = k;
        k = a % b;
    }
    node.x /= b;
    node.y /= b;
}

int main()
{
    // freopen("data", "r", stdin);
    vector<Node> v;
    int n;
    cin >> n;
    while (n--)
    {
        Node node;
        char c;
        cin >> node.x >> c >> node.y; 
        v.push_back(node);
    } 
    Node r = v[0];
    for (int i = 1; i < v.size(); ++i)
    {
        r = add(r, v[i]);
        f(r);
    }
    // cout << r.x << " " << r.y << endl;
    if (r.x % r.y == 0)
        cout << r.x / r.y << endl;
    else if (r.x > r.y)
        cout << r.x / r.y << " " << r.x % r.y << "/" << r.y  << endl;
    else 
        cout << r.x << "/" << r.y << endl;
    return 0;
}