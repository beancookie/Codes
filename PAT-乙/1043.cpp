#include <iostream>
using namespace std;

int a[6] = {0};

bool f()
{
    bool result = false;
    for (int i = 0; i < 6; ++i)
        if (a[i] > 0)
            result = true;
    return result;
}

int main()
{
    // freopen("1043.in", "r", stdin);
    char c;
    char tmp[] = {'P', 'A', 'T', 'e', 's', 't'};
    while (cin >> c)
    {
        switch(c){
            case 'P': a[0]++; break;
            case 'A': a[1]++; break;
            case 'T': a[2]++; break;
            case 'e': a[3]++; break;
            case 's': a[4]++; break;
            case 't': a[5]++; break;
        }
    }
    while(f())
    {
        for (int i = 0; i < 6; ++i)
            if (a[i] > 0)
            {
                cout << tmp[i];
                a[i]--;
            } 
    }
    return 0;
}