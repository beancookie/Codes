#include <iostream>
#include <string>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;

int N, M;

int main()
{
    // freopen("in/L2-012.in", "r", stdin);
    cin >> N >> M;
    vector<int> heap;
    for (int i = 0; i < N; ++i)
    {
        int x;
        cin >> x;   
        heap.push_back(x);
        push_heap(heap.begin(), heap.end(), greater<int>());
    }
    getchar();
    for (int i = 0; i < M; ++i)
    {
        string str;
        getline(cin, str);
        if (str.find("root") != -1)
        {
            int a;
            sscanf(str.c_str(), "%d", &a);
            if (heap[0] == a) cout << "T\n";
            else cout << "F\n";
        }
        else if (str.find("siblings") != -1)
        {
            int a, b;
            sscanf(str.c_str(), "%d%*s%d", &a, &b);
            int iA = -1, iB = -1;
            for (int i = 0; i < heap.size(); ++i)
            {
                if (heap[i] == a) iA = i;
                if (heap[i] == b) iB = i;
            }
            if (iA > iB) swap(iA, iB);
            if (iA % 2 && iA + 1 == iB) cout << "T\n";
            else cout << "F\n";
        }
        else if (str.find("parent") != -1)
        {
            int a, b;
            sscanf(str.c_str(), "%d%*s%*s%*s%*s%d", &a, &b);
            int iA = -1;
            int iB = -1;
            for (int i = 0; i < heap.size(); ++i)
            {
                if (heap[i] == a) iA = i;
                if (heap[i] == b) iB = i;
            }
            if ((iB - 1) / 2 == iA) cout << "T\n";
            else cout << "F\n";
        }
        else if (str.find("child") != -1)
        {
            int a, b;
            sscanf(str.c_str(), "%d%*s%*s%*s%*s%d", &a, &b);
            int iA = -1;
            int iB = -1;
            for (int i = 0; i < heap.size(); ++i)
            {
                if (heap[i] == a) iA = i;
                if (heap[i] == b) iB = i;
            }
            if ((iA - 1) / 2 == iB) cout << "T\n";
            else cout << "F\n";
        }
    }
    return 0;
}