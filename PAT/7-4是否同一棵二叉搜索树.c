#include <stdio.h>
#include <stdlib.h>
typedef struct TNode *Tree;

struct TNode 
{
    int v;
    Tree Left, Right;
    int flag;
};

Tree NewNode(int v)
{
    Tree t = (Tree) malloc(sizeof(struct TNode));
    t->v = v;
    t->Left = t->Right = NULL;
    t->flag = 0;
    return t;
}

Tree Insert(Tree t, int v)
{
    if (!t) t = NewNode(v);
    else 
    {
        if (v < t->v) Insert(t->Left, v);
        else Insert(t->Right, v);
    }
    return t;
}

Tree Create(int n)
{
    Tree t;
    int v;
    scanf("%d", &v);
    t = NewNode(v);
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &v);
        Insert(t, v);
    }
    return t;
}

int Check(Tree t, int v)
{
    if (t->flag)
    {
        if (v < t->v) return Check(t->Left, v);
        else if (v > t->v) return Check(t->Right, v);
        else return 0;
    }
    else 
    {
        if (v == t->v)
        {
            t->flag = 1;
            return 1;
        }
        else return 0;
    }
}

int Judge(Tree t, int n)
{
    int v, flag = 0;
    scanf("%d", &v);
    if (v != t->v) flag = 1;
    for (int i = 1; i < n; ++i)
    {
        scanf("%d", &v);
        if (!flag && !Check(t, v))
            flag = 1;
    }
    if (flag) return 0;
    else return 1;
}

void Reset(Tree t)
{
    if (t->Left) Reset(t->Left);
    if (t->Right) Reset(t->Right);
    t->flag = 0;
}

void Free(Tree t)
{
    if (t->Left) Free(t->Left);
    if (t->Right) Free(t->Right);
    free(t);
}

int main()
{
    // freopen("in/7-4.in", "r", stdin);
    int n, l;
    Tree t;
    scanf("%d", &n);
    while (n)
    {
        scanf("%d", &l);
        t = Create(n);
        for (int i = 0; i < l; ++i)
        {
            if (Judge(t, n)) printf("Yes\n");
            else printf("No\n");
            Reset(t);
        }
        Free(t);
        scanf("%d", &n);
    }
    return 0;
}