#include <iostream>
#include <vector>
using namespace std;

struct Node
{
    int data;
    Node *left, *right;
};

Node *Insert(Node *t, int data)
{
    if (!t)
    {
        t = new Node;
        t->data = data;
        t->left = t->right = NULL;
    }
    else 
    {
        if (data < t->data)
            t->left = Insert(t->left, data);
        else if (data >= t->data)
            t->right = Insert(t->right, data);
    }
    return t;
}

bool isEqual = true;

void PreOrder(Node *t, vector<int> &tmp)
{
    if (t)
    {
        tmp.push_back(t->data);
        PreOrder(t->left, tmp);
        PreOrder(t->right, tmp);
    }
}

void Mirror(Node *t)
{
    if (t)
    {
        Mirror(t->left);
        Mirror(t->right);
        swap(t->left, t->right);
    }
}

bool flag = true;
void PostOrder(Node *t)
{
    if (t)
    {
        PostOrder(t->left);
        PostOrder(t->right);
        if (flag) flag = false;
        else cout << " ";
        cout << t->data;
    }
}

int main()
{
    freopen("in/L2-004.in", "r", stdin);
    int n;
    cin >> n;
    vector<int> pre;
    Node *t = new Node;
    t->left = t->right = NULL;
    cin >> t->data;
    pre.push_back(t->data);
    for (int i = 1; i < n; ++i)
    {
        int d;
        cin >> d;
        pre.push_back(d);
        Insert(t, d);
    }
    isEqual = true;
    vector<int> tmp;
    PreOrder(t, tmp);
    for (int i = 0; i < tmp.size(); ++i)
        if (tmp[i] != pre[i]) isEqual = false;
    
    if (isEqual)
    {
        cout << "YES\n";
        PostOrder(t);
        return 0;
    }
    else 
    {
        Mirror(t);
        isEqual = true;
        tmp.clear();
        PreOrder(t, tmp);
        for (int i = 0; i < tmp.size(); ++i)
            if (tmp[i] != pre[i]) isEqual = false;
        
        if (isEqual)
        {
            cout << "YES\n";
            PostOrder(t);
            return 0;
        }
    }
    cout << "NO";
    return 0;
}