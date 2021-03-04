#include <bits/stdc++.h>
using namespace std;

class Matrix {
    int m[2][3];
    friend istream &operator>>(istream &in, Matrix &ma) {
        for (int i = 0; i < 2; i++)
            for (int j = 0; j < 3; j++) in >> ma.m[i][j];
        return in;
    }

    friend ostream &operator<<(ostream &out, const Matrix &ma) {
        for (int i = 0; i < 2; i++) {
            for (int j = 0; j < 3; j++) out << ma.m[i][j] << " ";
            out << endl;
        }
        return out;
    }
};

int main() {
    Matrix ma;
    cin >> ma;
    cout << ma;
    return 0;
}