#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

const int MAX_N = 100005;

struct T 
{
    int loc, data, next;
};

T List[MAX_N];
vector<T> v1;
vector<T> v2;

int main()
{
    freopen("in/L2-022.in", "r", stdin);
    int head, n;
    cin >> head >> n;
    for (int i = 0; i < n; ++i)
    {
        int loc, data, next;
        cin >> loc >> data >> next;
        List[loc].loc = loc;
        List[loc].data = data;
        List[loc].next = next;
    }
    int p = head;
    int i = 0;
    int mid;
    if (n % 2 == 0)
        mid = n / 2;
    else 
        mid = n / 2 + 1;
    while (p != -1)
    {
        if (i++ < mid)
            v1.push_back(List[p]);
        else 
            v2.push_back(List[p]);
        p = List[p].next;
    }
    reverse(v2.begin(), v2.end());
    for (int i = 0; i < mid - 1; ++i)
    {
        printf("%05d %d %05d\n", v2[i].loc, v2[i].data, v1[i].loc);
        printf("%05d %d %05d\n", v1[i].loc, v1[i].data, v2[i + 1].loc);
    }
    if (mid % 2 == 0)
        printf("%05d %d -1", v1[mid-1].loc, v1[mid-1].data);
    else 
    {
        printf("%05d %d %05d\n", v2[mid-1].loc, v2[mid-1].data, v1[mid-1].loc);
        printf("%05d %d -1", v1[mid-1].loc, v1[mid-1].data);
    }   
    return 0;
}