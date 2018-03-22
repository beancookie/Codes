#include <iostream>
#include <cstring>
using namespace std;

const int MAXN = 10;
typedef int Tree;
const int Null = -1;

struct TNode 
{
    char E;
    Tree Left, Right;
} T1[MAXN], T2[MAXN];

Tree Build(struct TNode T[])
{
    int n;
    cin >> n;;
    bool check[n];
    if (n)
    {
        memset(check, 0, sizeof(check));
        for (int i = 0; i < n; ++i)
        {
            char cl, cr;
            cin >> T[i].E >> cl >> cr;
            if (cl != '-')
            {
                T[i].Left = cl - '0';
                check[T[i].Left] = true;
            }
            else T[i].Left = Null;
            if (cr != '-')
            {
                T[i].Right = cr - '0';
                check[T[i].Right] = true;
            }
            else T[i].Right = Null;
        }
        for (int i = 0; i < n; ++i)
            if (!check[i]) 
                return i;
    }
    return Null;
}

bool Isomorphic(Tree r1, Tree r2)
{
    if (r1 == Null && r2 == Null)
        return true;
    if ((r1 == Null && r2 != Null) || (r1 != Null && r2 == Null))
        return false;
    if (T1[r1].E != T2[r2].E)
        return false;
    if (T1[r1].Left == Null && T1[r2].Left == Null)
        return Isomorphic(T1[r1].Right, T2[r2].Right);
    if (T1[r1].Left != Null && T2[r2].Left != Null && T1[T1[r1].Left].E == T2[T2[r2].Left].E)
        return Isomorphic(T1[r1].Left, T2[r2].Left) && Isomorphic(T1[r1].Right, T2[r2].Right);
    else 
        return Isomorphic(T1[r1].Left, T2[r2].Right) && Isomorphic(T1[r1].Right, T2[r2].Left);
}

int main()
{
    // freopen("in/7-3.in", "r", stdin);
    Tree r1, r2;
    r1 = Build(T1);
    r2 = Build(T2);
    if (Isomorphic(r1, r2))
        cout << "Yes";
    else 
        cout << "No";
    return 0;
}