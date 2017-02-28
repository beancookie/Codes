#include <iostream>

using namespace std;

int main(void)
{
    unsigned int a = 0xffffffff;
    cout << "a = " << a << endl;
    unsigned int b = a + 1;
    cout << "b = " << b << endl;
    cin >> a;
    cout << "a = " << a << endl;
    return 0;
}