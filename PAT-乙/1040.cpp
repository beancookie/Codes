#include <iostream>
#include <string>
using namespace std;

int main()
{
    freopen("1040.in", "r", stdin);
    int pn = 0, an = 0, tn = 0;
    bool fa = false, ft = false;
    string s;
    getline(cin, s);
    int len = s.length();
    int fristA = s1.find_first_of('A');
    int fristA = s1.find_first_of('A');
    for (int i = len - 1; i >= 0; --i)
    {
        cout << i << " " << s[i] << endl;
        if (s[i] == 'A')
            fa = true;
        if (s[i] == 'T')
            ft = true;
        if (ft && s[i] == 'T')
            tn++;
        if (ft && fa && s[i] == 'A')
            an++;
        if (ft && fa && s[i] == 'P')
            pn++;
    }
    cout << pn << " " << an << " " << tn << endl;
    return 0;
}