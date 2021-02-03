#include <bits/stdc++.h>
using namespace std;

class Date {
    int year, month, day, hour, minute, second;

    friend class Time;

   public:
    Date(int _year, int _month, int _day, int _hour, int _minute, int _second)
        : year(_year),
          month(_month),
          day(_day),
          hour(_hour),
          minute(_minute),
          second(_second) {}
};

class Time {
   public:
    void display(const Date &date) {
        printf("%d/%d/%d, %d:%02d:%02d", date.year, date.month, date.day,
               date.hour, date.minute, date.second);
    }
};
int main() {
    Date date(2000, 11, 24, 19, 0, 20);
    Time time;
    time.display(date);
    return 0;
}