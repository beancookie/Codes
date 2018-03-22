#include <iostream>
#include <cmath>
#include <vector>
#include <iomanip>
using namespace std;

const int MAX_N = 100005;
struct Node
{
    int loc, data, next;
};

Node List[MAX_N];
bool Visited[MAX_N];

int main()
{
    freopen("in/L2-002.in", "r", stdin);
    int head, n;
    cin >> head >> n;
    for (int i = 0; i < n; ++i)
    {
        int loc;
        cin >> loc;
        cin >> List[loc].data >> List[loc].next;
        List[loc].loc = loc;
    }
    int p = head;
    int newHead = -1;
    vector<Node> l1, l2;
    while (p != -1)
    {
        int data = List[p].data;
        if (!Visited[abs(data)])
        {
            Visited[abs(data)] = true;
            l1.push_back(List[p]);
        }
        else 
        {
            l2.push_back(List[p]);
        }
        p = List[p].next;
    }
    for (int i = 0; i < l1.size(); ++i)
    {
        if (i == l1.size() - 1)
            printf("%05d %d -1\n", l1[i].loc, l1[i].data);
        else 
            printf("%05d %d %05d\n", l1[i].loc, l1[i].data, l1[i+1].loc);
    }
    for (int i = 0; i < l2.size(); ++i)
    {
        if (i == l2.size() - 1)
            printf("%05d %d -1", l2[i].loc, l2[i].data);
        else 
            printf("%05d %d %05d\n", l2[i].loc, l2[i].data, l2[i+1].loc);
    }
    return 0;
}