#include <iostream>
#include <string>
#include <cstring>
#include <cctype>
using namespace std;

#define N 20

typedef struct Node
{
    int a, b;
} NODE;

NODE add(int a, int b, int k)
{
    NODE node;
    int sum = a + b;
    node.a = sum / k;
    node.b = sum % k;
    return node;
}

int main()
{
    // freopen("data", "r", stdin);
    string m, s1, s2;
    getline(cin, m);
    getline(cin, s1);
    getline(cin, s2);
    int len1 = s1.length();
    int len2 = s2.length();
    int lenk = m.length();
    if (len2 > len1)
    {
        swap(s1, s2);
        swap(len1, len2);
    }
    int i, j, k;
    int cnt = 0;
    int t = 0;
    for (i = len1 - 1, j = len2 - 1, k = lenk - 1; i >= 0 || j >= 0; --i, --j, --k)
    {
        cnt++;
        int a = s1[i] - '0', b = s2[j] - '0', c = m[k] - '0';
        if (c == 0 || k < 0)
            c = 10;
        if (j < 0)
            b = 0;
        NODE node = add(a, b, c);
        // cout << a << " " << b << " " << c << endl;
        s1[i] = node.b + '0';
        if (i > 0)
            s1[i - 1] += node.a;
        else if (i == 0)
            t = node.a;
    }
    bool flag = false;
    if (t)
    {
        cout << t;
        cout << s1;
    }
    else 
    {
        for (int i = 0; s1[i]; ++i)
        {
            if (s1[i] - '0' != 0)
            {
                cout << s1[i];
                flag = true;
            }
            else if (flag)
                cout << s1[i];
        }
    }
    return 0;
}