#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main()
{
    string s = "I Love GPLT";
    vector<char> v;
    for (int i = 0; s[i] != '\0'; ++i)
        v.push_back(s[i]);
    
    for (int i = 0; i < v.size(); ++i)
        cout << v[i] << endl;
    return 0;
}