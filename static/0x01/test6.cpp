/*************************************************************************
    > File Name: test6.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 19:08:49 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
const double Pi = 3.14159;
class Circle {
   private:
    double Radius;

   public:
    Circle(double = 0.0);
    double GetArea();
};

Circle::Circle(double r) : Radius(r) {}

double Circle::GetArea() { return Pi * Radius * Radius; }

int main() {
    Circle circle(1.4);
    cout << circle.GetArea() << '\n';
    return 0;
}
