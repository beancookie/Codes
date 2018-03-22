#include <iostream>
#include <queue>
using namespace std;

const int MAX_N = 35;

int Pre[MAX_N];
int In[MAX_N];

struct T
{
    T *left, *right;
    int data;
};

T *Build(int inL, int preL, int n)
{
    if (n <= 0)
        return NULL;
    int root = Pre[preL];
    // cout << root << endl;
    T *node = new T;
    node->data = root;
    int i;
    for (i = 0; i < n; ++i)
        if (root == In[inL + i])
            break;
    int ln = i;
    int rn = n - i - 1;
    node->left = Build(inL, preL + 1, ln);
    node->right = Build(inL + ln + 1, preL + ln + 1, rn);
    return node;
}

bool flag = true;

void LevelOrder(T *tree)
{
    queue<T *> q;
    q.push(tree);
    while (!q.empty())
    {
        T *node = q.front();
        q.pop();
        if (flag) flag = false;
        else cout << " ";
        cout << node->data;
        if (node->right) q.push(node->right);
        if (node->left) q.push(node->left);
    }
}

int main()
{
    // freopen("in/L2-011.in", "r", stdin);
    int n;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> In[i];
    for (int i = 0; i < n; ++i)
        cin >> Pre[i];
    T *tree = Build(0, 0, n);
    LevelOrder(tree);
    return 0;
}