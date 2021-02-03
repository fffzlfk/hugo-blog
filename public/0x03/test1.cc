#include <bits/stdc++.h>
using namespace std;

class Complex {
    double real, imag;

   public:
    Complex() = default;
    Complex(double _real, double _imag) : real(_real), imag(_imag) {}
    Complex operator+(const Complex &t) {
        return Complex(real + t.real, imag + t.imag);
    }
    Complex operator-(const Complex &t) {
        return Complex(real - t.real, imag - t.imag);
    }
    Complex operator*(const Complex &t) {
        double r = real * t.real - imag * t.imag;
        double i = real * t.imag + imag * t.imag;
        return Complex(r, i);
    }
    Complex operator/(const Complex &t) {
        double div = t.real * t.real + t.imag * t.imag;
        double r = (real * t.real + imag * t.imag) / div;
        double i = (t.real * imag - t.imag * real) / div;
        return Complex(r, i);
    }

    void show() { cout << real << '+' << imag << 'i' << '\n'; }
};

int main() {
    Complex a(1, 1);
    Complex b(2, 2);
    (a + b).show();
    (a - b).show();
    (a * b).show();
    (a / b).show();
    return 0;
}