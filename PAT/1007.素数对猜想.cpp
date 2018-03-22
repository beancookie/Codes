#include <iostream>
#include <vector>
using namespace std;

int N;
vector<int> V;

bool isP(int x)
{
    for (int i = 0; i < V.size(); ++i)
        if (x % V[i] == 0)
            return false;
    return true;
}

void f()
{
    for (int i = 2; i <= N; ++i)
        if (isP(i))
            V.push_back(i);
}

int main()
{
    int cnt = 0;
    cin >> N;
    // N = 20;
    f();
    for (int i = 0; i < V.size() - 1; ++i)
    {
        if (V[i+1] - V[i] == 2) cnt++;
    }
    cout << cnt;
    return 0;
}