#include <iostream>
#include <algorithm>
#include <string>
#include <map>
#include <set>
using namespace std;

int N;

struct T 
{
    string id, school;
    double grade;
};

struct S 
{
    string name;
    double grade;
    int num;
};

struct Rule 
{
    bool operator() (const S &a, const S &b)
    {
        if (a.grade != b.grade)
            return a.grade > b.grade;
        else if (a.num != b.num)
            return a.num < b.num;
        else 
            return a.name < b.name;
    }
};

int main()
{
    // freopen("1085.in", "r", stdin);
    cin >> N;
    map<string, S> mp;
    set<S, Rule> st;
    for (int i = 0; i < N; ++i)
    {
        T t;
        cin >> t.id >> t.grade >> t.school;
        transform(t.school.begin(), t.school.end(), t.school.begin(), ::tolower);
        double grade = 0;
        if (t.id[0] == 'B')
            grade += t.grade / 1.5;
        else if (t.id[0] == 'A')
            grade += t.grade;
        else if (t.id[0] == 'T')
            grade += t.grade * 1.5;

        if (mp.find(t.school) == mp.end())
        {
            S s;
            s.grade = grade;
            s.num = 1;
            mp.insert(make_pair(t.school, s));
        }
        else 
        {
            mp[t.school].grade += grade;
            mp[t.school].num++;
        }
    }

    for (auto it = mp.begin(); it != mp.end(); ++it)
    {
        S s;
        s.name = it->first;
        s.grade = it->second.grade;
        s.num = it->second.num;
        st.insert(s);
    }
    int befGrade = st.begin()->grade;
    int index = 1;
    int i = 1;
    cout << st.size() << endl;
    for (auto e : st)
    {
        if (befGrade > e.grade)
            index = i; 
        befGrade = e.grade;
        printf("%d %s %d %d\n", index, e.name.c_str(), (int)e.grade, e.num);
        i++;
    }
    return 0;
}