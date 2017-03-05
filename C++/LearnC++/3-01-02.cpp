#include <iostream>

using namespace std;

int monthDays[13] = {-1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

// 2012 1 22是星期天,输入一个日期输出星期几
int main(void)
{
    int year, month, day, days = 0;
    bool isLeap = 0;
    cin >> year >> month >> day;
    // 看做整年
    for (int y = 2012; y < year; ++y)
    {
        if (y % 4 == 0 && y % 100 != 0 || y % 400 == 0)
            // 闰年
            days += 366;
        else
            days += 365;
    }
    // 算出相差月份
    if (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)
        monthDays[2] = 29;
    for (int m = 1; m < month; ++m)
        days += monthDays[m];
    days += day;
    // 减去多算天数
    days -= 22;
    cout << "days = " << days << endl;
    cout << days % 7 << endl;
    return 0;
}