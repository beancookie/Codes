    #include <iostream>
    #include <cmath>
    using namespace std;

    const int MAXN = 1e4 + 5;

    bool isPrime(int x)
    {
        if (x < 2) return false;
        for (int i = 2; i <= sqrt(x); ++i)
            if (x % i == 0  )
                return false;
        return true;
    }

    int main()
    {
        // freopen("in/1013.in", "r", stdin);
        int a, b;
        cin >> a >> b;
        int t = 1;
        int i;
        for (i = 2; t < a; ++i)
            if (isPrime(i))
                t++;
        int count = 0;
        for (; t <= b; ++i)
        {
            if (isPrime(i))
            {
                if (++count % 10 == 0) cout << i << "\n";
                else if (t == b) cout << i;
                else cout << i << " ";
                t++;
            }
        }
        return 0;
    }