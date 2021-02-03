/* Author: fffzlfk */
#include <bits/stdc++.h>
using namespace std;

class Dog {
    char *name;
    int age, weight;
    char sex;

   public:
    Dog(const char *_name, int _age, char _sex, int _weight)
        : age(_age), sex(_sex), weight(_weight) {
        name = new char[strlen(_name) + 1];
        strcpy(name, _name);
    }
    ~Dog() { delete name; }

    void Show() {
        cout << "name = " << name << '\n';
        cout << "age = " << age << '\n';
        cout << "sex = " << sex << '\n';
        cout << "weight = " << weight << '\n';
    }
};

int main() {
    Dog *pdog = new Dog("ATao", 12, 'F', 30);
    pdog->Show();
    return 0;
}
