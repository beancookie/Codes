#include <iostream>
#include <vector>
#include <string>
using namespace std;

typedef struct Node 
{
    int n;
    char c;
} Node;

vector<Node> fc(string str)
{
    vector<Node> v;
    int cnt = 0;
    for (int i = 0; str[i]; ++i)
    {
        cnt++;
        if (str[i] == str[i+1]) continue;
        Node node = {cnt, str[i]};
        v.push_back(node);
        cnt = 0;
    }
    return v;
}

int main()
{
    // freopen("data", "r", stdin);
    char c;
    cin >> c;
    getchar();
    string str;
    getline(cin, str);
    if (c == 'C')
    {
        vector<Node> v = fc(str);
        for (vector<Node>::iterator i = v.begin(); i != v.end(); ++i)
        {
            if (i->n == 1) cout << i->c;
            else cout << i->n << i->c;
        }
    } 
    else if (c == 'D')
    {
        vector<Node> v;
        for (int i = 0; str[i]; ++i)
        {
            Node node;
            if (str[i] < '0' || str[i] > '9')
            {
                node.c = str[i];
                node.n = 1;
                v.push_back(node);
            } 
            else 
            {
                int num = str[i] - '0';
                int j;
                for (j = 1; str[i+j] >= '0' && str[i+j] <= '9'; ++j)
                    num = num * 10 + str[i+j] - '0';
                node.n = num;
                node.c = str[i+j];
                v.push_back(node);
                i += j;
            }
        }
        for (vector<Node>::iterator i = v.begin(); i != v.end(); ++i)
        {
            for (int j = 0; j < i->n; ++j) cout << i->c;
        }
    } 
}