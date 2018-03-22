#include <iostream>
#include <iomanip>
#include <algorithm>
#include <vector>
#include <cstring>
using namespace std;

typedef struct
{
    int id;
    char name[9];
    int grade;
} CARD;

struct Rule1
{
    bool operator()(const CARD &a, const CARD &b) const
    {
        return a.id <= b.id;
    }
};

struct Rule2
{
    bool operator()(const CARD &a, const CARD &b) const
    {
        if (strcmp(a.name, b.name) == 0)
            return a.id < b.id;
        else
            return strcmp(a.name, b.name) < 0;
    }
};

struct Rule3
{
    bool operator()(const CARD &a, const CARD &b) const
    {
        if (a.grade == b.grade)
            return a.id < b.id;
        else
            return a.grade < b.grade;
    }
};

int main()
{
    freopen("data", "r", stdin);
    int n, c;
    cin >> n >> c;
    CARD cards[n];
    for (int i = 0; i < n; ++i)
    {
        CARD card;
        cin >> card.id >> card.name >> card.grade;
        cards[i] = card;
    }
    if (c == 1)
        sort(cards, cards+n, Rule1());
    else if (c == 2)
        sort(cards, cards+n, Rule2());
    else
        sort(cards, cards+n, Rule3());

    for (int i = 0; i < n; ++i)
        cout << setw(6) << setfill('0') << cards[i].id << " " << cards[i].name << " " << cards[i].grade << "\n";
    return 0;
}