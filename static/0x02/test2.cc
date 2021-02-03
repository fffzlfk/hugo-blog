/* Author: fffzlfk */
#include <bits/stdc++.h>
using namespace std;

class Student {
    char name[18];
    int num, mathScore, englishScore;
    static int count, mathTotalScore, englishTotalScore;

   public:
    Student(const char *nm, int nu, int math, int english)
        : num(nu), mathScore(math), englishScore(english) {
        strcpy(name, nm);
        count++;
        mathTotalScore += mathScore;
        englishTotalScore += englishScore;
    }

    void ShowBase() {
        cout << "name = " << name << '\n';
        cout << "num = " << num << '\n';
        cout << "mathScore = " << mathScore << '\n';
        cout << "englishScore = " << englishScore << '\n';
    }

    static void ShowStatic() {
        cout << "count = " << count << '\n';
        cout << "mathTotalScore = " << mathTotalScore << '\n';
        cout << "englishTotalScore = " << englishTotalScore << '\n';
    }
};

int Student::count = 0;
int Student::mathTotalScore = 0;
int Student::englishTotalScore = 0;

int main() {
    Student s1("Li Ming", 1801, 89, 77);
    Student s2("Zhang san", 1802, 99, 60);
    Student s3("Li Si", 1803, 100, 100);
    s1.ShowBase();
    s2.ShowBase();
    s3.ShowBase();
    Student::ShowStatic();
    return 0;
}
