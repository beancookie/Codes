#include <iostream>
#include <vector>
using namespace std;

#define N 10001

int main()
{
    // freopen("data", "r", stdin);
    vector<char> v1;
    vector<char> v2;
    char c[N];
    cin.getline(c, N);
    for (int i = 0; c[i] != '\0'; ++i)
        v1.push_back(c[i]);

    cin.getline(c, N);

    for (int i = 0; c[i] != '\0'; ++i)
        v2.push_back(c[i]);

    for (vector<char>::iterator i = v1.begin(); i != v1.end(); ++i)
        for (int j = 0; j < v2.size(); ++j)
        {
            if (*i == v2[j])
                v1.erase(i);
        }
    
    for (int i = 0; i < v1.size(); i++)
        cout << v1[i];

    return 0;
}