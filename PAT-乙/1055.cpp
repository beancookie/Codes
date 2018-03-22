#include <iostream>
#include <algorithm>
#include <string>
#include <cmath>
#include <list>
using namespace std;

int N, K;

struct T
{
    string name;
    int h;
};

bool cmp(const T &a, const T &b)
{
    if (a.h == b.h)
        return a.name > b.name;
    else 
        return a.h <= b.h;
}

int main()
{
    freopen("1055.in", "r", stdin);
    cin >> N >> K;
    T a[N];
    list<T> lt[K];
    for (int i = 0; i < N; ++i)
        cin >> a[i].name >> a[i].h;
    sort(a, a + N, cmp);
    int t = floor(N * 1.0 / K);
    for (int i = 0; i < t * K; ++i)
    {
        lt[i / K].push_back(a[i]);
    }
    for (int i = t * K; i < N; ++i)
        lt[K - 1].push_back(a[i]);
    for (int i = K - 1; i >= 0; --i)
    {
        int size = lt[i].size();
        T tmp[size];
        int l = 0, r = size - 1;
        for (int j = 0; j < size / 2; ++j)
        {
            tmp[l++] = lt[i].front();
            lt[i].pop_front();
            tmp[r--] = lt[i].back();
            lt[i].pop_back();
        }
        if (size % 2 == 1)
            tmp[size / 2] = lt[i].front();
        bool flag = true;
        for (int i = 0; i < size; ++i)
        {
            if (flag) flag = false;
            else cout << " ";
            cout << tmp[i].name;
        }
        cout << endl;
    }
    return 0;
}