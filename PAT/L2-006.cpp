#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 35;
int In[MAX_N];
int Post[MAX_N];

struct T 
{
    T *left, *right;
    int data;
};

T *Solve(int postL, int inL, int n)
{
    if (n <= 0) return NULL;
    int root = Post[postL + n - 1];
    T *t = new T;
    t->data = root;
    int i;
    for (i = 0; i < n; ++i)
        if (root == In[inL + i])
            break;
    int ln = i;
    int rn = n - i - 1;
    t->left = Solve(postL, inL, ln);
    t->right = Solve(postL + ln, inL + ln + 1, rn);
    return t;
}

bool flag = true;

void InOrder(T * tree)
{
    queue<T*> q;
    q.push(tree);
    while (!q.empty())
    {
        if (flag) flag = false;
        else cout << " ";
        T *node = q.front();
        cout << node->data;
        q.pop();
        if (node->left) q.push(node->left);
        if (node->right) q.push(node->right);
    }
}

int main()
{
    freopen("in/L2-006.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> Post[i];
    for (int i = 0; i < n; ++i)
        cin >> In[i];
    T *tree = Solve(0, 0, n);
    InOrder(tree);
    return 0;
}