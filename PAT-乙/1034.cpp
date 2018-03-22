#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

struct T 
{
    int k, w, c;
};

int main()
{
    freopen("1034.in", "r", stdin);
    string str;
    getline(cin, str);
    int a, b, c, d;
    sscanf(str.data(), "%d/%d %d/%d", &a, &b, &c, &d);
    T a, b;
    return 0;
}