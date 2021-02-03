/*************************************************************************
    > File Name: test5.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 18:59:02 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Date {
   private:
    int year, month, day;

   public:
    void setDate();
    void showDate();
};
void Date::setDate() {
    cout << "Please Input Date\n";
    cin >> year >> month >> day;
}

void Date::showDate() {
    cout << "Date is: " << year << ',' << month << ',' << day << '\n';
}

int main() {
    Date date;
    date.setDate();
    date.showDate();
    return 0;
}
