#include <bits/stdc++.h>
using namespace std;
const double PI = 3.141593;
class Shape {
   public:
    virtual double area() = 0;
};

class Cicle : public Shape {
    double radius;

   public:
    Cicle(double _radius) : radius(_radius) {}
    double area() { return PI * radius * radius; }
};

class Square : public Shape {
    double sideLength;

   public:
    Square(double a) : sideLength(a) {}
    double area() { return sideLength * sideLength; }
};
class Rectangle : public Shape {
    double a, b;

   public:
    Rectangle(double _a, double _b) : a(_a), b(_b) {}
    double area() { return a * b; }
};

class Trapezoid : public Shape {
    double a, b, h;

   public:
    Trapezoid(double _a, double _b, double _h) : a(_a), b(_b), h(_h) {}
    double area() { return (a + b) * h / 2; }
};
class Triangle : public Shape {
    double a, b, c;

   public:
    Triangle(double _a, double _b, double _c) : a(_a), b(_b), c(_c) {}
    double area() {
        double p = (a + b + c) / 2;
        return sqrt(p * (p - a) * (p - b) * (p - c));
    }
};
int main() {
    Shape *shape[5] = {new Cicle(2), new Square(3), new Rectangle(2, 5),
                       new Trapezoid(1, 2, 3), new Triangle(1, 2, 1.732)};
    double circumSum = 0.0;
    for (int i = 0; i < 5; i++) {
        circumSum += shape[i]->area();
        cout << shape[i]->area() << '\n';
    }
    cout << "Sum = " << circumSum << '\n';
    return 0;
}