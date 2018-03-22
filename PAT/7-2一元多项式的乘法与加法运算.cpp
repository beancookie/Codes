#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

struct Node
{
    int c, e;
};

struct Cmp
{
    bool operator() (const Node &a, const Node &b) const
    {
        return a.e > b.e;
    }
};

int main()
{
    freopen("in/7-2.in", "r", stdin);
    list<Node> l1, l2;
    int n;
    cin >> n;
    while (n--)
    {
        Node node;
        cin >> node.c >> node.e;
        l1.push_back(node);
    }
    cin >> n;
    while (n--)
    {
        Node node;
        cin >> node.c >> node.e;
        l2.push_back(node);
    }
    list<Node> l3, l4;
    // 乘法
    auto it1 = l1.begin();
    for (auto it2 = l2.begin(); it2 != l2.end(); ++it2)
    {
        Node node;
        node.c = it1->c * it2->c;
        node.e = it1->e + it2->e;
        l3.push_back(node);
    }
    it1++;
    while (it1 != l1.end())
    {
        Node node;
        node.c = it1->c * 
    }

    // 加法
    auto it1 = l1.begin(), it2 = l2.begin();
    for (; it1 != l1.end() && it2 != l2.end(); )
    {
        Node node;
        if (it1->e == it2->e)
        {
            node.c = it1->c + it2->c;
            node.e = it1->e;
            if (node.c != 0)
                l4.push_back(node);
            it1++;
            it2++;
        } 
        else if (it1->e > it2->e) 
        {
            node.c = it1->c;
            node.e = it1->e;
            l4.push_back(node);
            it1++;
        } 
        else
        {
            node.c = it2->c;
            node.e = it2->e;
            l4.push_back(node);
            it2++;
        }
    }
    for (; it1 != l1.end(); ++it1)
    {
        Node node;
        node.c = it1->c;
        node.e = it1->e;
        l4.push_back(node);   
    }

    for (; it2 != l2.end(); ++it2)
    {
        Node node;
        node.c = it2->c;
        node.e = it2->e;
        l4.push_back(node);   
    }
    l3.sort(Cmp());
    bool flag = true;
    for (auto it = l3.begin(); it != l3.end(); ++it)
    {
        if (flag) flag = false;
        else cout << " ";
        cout << it->c << " " << it->e;
    }
    cout << endl;
    flag = true;
    for (auto it = l4.begin(); it != l4.end(); ++it)
    {
        if (flag) flag = false;
        else cout << " ";
        cout << it->c << " " << it->e;
    }
    
    return 0;
}