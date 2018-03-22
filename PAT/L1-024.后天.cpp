#include <iostream>
using namespace std;

int main()
{
    int x;
    cin >> x;
    if (x <= 5)
        x += 2;
    else 
        x -= 5;
    cout << x;
    return 0;
}