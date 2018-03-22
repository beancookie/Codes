#include <iostream>
#include <iomanip>
using namespace std;

const int MAXN = 100005;
struct T
{
    int data, next;
};

T List[MAXN];

int main()
{
    // freopen("1025.in", "r", stdin);
    int head, n, k;
    cin >> head >> n >> k;
    for (int i = 0; i < n; ++i)
    {
        int index, data, next;
        cin >> index;
        cin >> List[index].data >> List[index].next;
    }
    int old = head, newNode = -1, tmp;
    for (int i = 0; i < k && old != -1; ++i)
    {
        tmp = List[old].next;
        List[old].next = newNode;
        newNode = old;
        old = tmp;
    }
    List[head].next = tmp;
    head = newNode;
    while (head != -1)
    {
        if (List[head].next != -1)
            cout << setw(5) << setfill('0') << head << " " << List[head].data << " " << setw(5) << setfill('0') << List[head].next << endl;
        else 
            cout << setw(5) << setfill('0') << head << " " << List[head].data << " -1" << endl;
        head = List[head].next;
    }
    return 0;
}