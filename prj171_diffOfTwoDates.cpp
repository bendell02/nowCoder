#include <iostream>
#include <cstdlib>

using namespace std;

int cumMonthLeapYear[12] = {0, 31, 60, 91, 121, 152, 182, 213, 244, 274, 305, 335};
int cumMonthCommonYear[12] = {0, 31, 59, 90, 120, 151, 181, 212, 243, 273, 304, 334};

bool isLeapYear(int &year)
{
    if((year%4==0 && year%100) || year%400==0) {
        return true;
    } else {
        return false;
    }
}

int getDays(int &year, int &month, int &day)
{
    int days = (year-1)*365 + (year-1)/4 - (year-1)/100 + (year-1)/400;
    if(isLeapYear(year)) {
        days += cumMonthLeapYear[month-1];
    } else {
        days += cumMonthCommonYear[month-1];
    }
    days += day;
    return days;
}

void resolveDate(int &date, int &y, int&m, int &d)
{
    y = date/10000;
    m = (date%10000)/100;
    d = date%100;
}

int main()
{
    int date1, date2; int y1, y2, m1, m2, d1, d2;
    while(cin >> date1 >> date2) {
        resolveDate(date1, y1, m1, d1);
        resolveDate(date2, y2, m2, d2);
        cout << abs(getDays(y1, m1, d1)-getDays(y2, m2, d2))+1 << endl;
    }
    return 0;
}
