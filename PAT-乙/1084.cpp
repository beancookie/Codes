#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

string d;

string f(string d)
{
    vector<pair<char, int> > v;
    ostringstream oss;
    for (char e : d)
    {
        if (!v.empty() && v[v.size()-1].first == e)
            v[v.size()-1].second++;
        else 
            v.push_back(make_pair(e, 1));
    }
    vector<pair<char, int> > v;

    v[v.size()-1].first;
    v.end()->first;
    
    for (auto e : v)
        oss << e.first << e.second;
    return oss.str();
}

int main()
{
    // freopen("1084.in", "r", stdin);
    string d; 
    int n;
    cin >> d >> n;
    for (int i = 0; i < n - 1; ++i)
        d = f(d);
    cout << d;
    return 0;
}