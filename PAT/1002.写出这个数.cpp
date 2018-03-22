#include <iostream>
#include <string>
#include <sstream>
#include <stack>
using namespace std;

string names[] = {"ling", "yi", "er", "san", "si", "wu", "liu", "qi", "ba", "jiu"};

int main()
{
    // freopen("in/1002.in", "r", stdin);
    string line;
    getline(cin, line);
    int sum = 0;
    for (int i = 0; i < line.length(); ++i)
        sum += line[i] - '0';
    stack<string> s;
    while (sum)
    {
        s.push(names[sum % 10]);
        sum /= 10;
    }
    while (!s.empty())
    {
        cout << s.top(); s.pop();
        if (!s.empty()) cout << " ";
    }
    return 0;
}