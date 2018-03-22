#include <iostream>
#include <set>
using namespace std;

struct Node
{
    float n, tp;
    float p;
    bool operator<(const Node &other)
    {
        return p > other.p;
    }
};

struct Rule
{
    bool operator()(const Node &a, const Node &b)
    {
        return a.p > b.p;
    }
};

bool cmp(const Node &a, const Node &b)
{
    return a.p > b.p;
}

int main()
{
    freopen("in/L2-003.in", "r", stdin);
    int n, d;
    set<Node, Rule> st;
    scanf("%d %d", &n, &d);
    int a[2][n];
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[0][i]);
    for (int i = 0; i < n; ++i)
        scanf("%d", &a[1][i]);
    for (int i = 0; i < n; ++i)
    {
        Node node;
        node.n = a[0][i];
        node.tp = a[1][i];
        node.p = (float)node.tp / node.n;
        st.insert(node);
    }
    double total = 0;
    for (set<Node, Rule>::iterator it = st.begin(); it != st.end(); ++it)
    {
        if (d >= it->n)
        {
            total += it->tp;
            d -= it->n;
        }
        else
        {
            total += d * it->p;
            break;
        }
    }
    printf("%.2f", total);
    return 0;
}