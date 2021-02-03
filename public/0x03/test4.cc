#include <bits/stdc++.h>
using namespace std;

class Teacher {
   protected:
    string name, address, tel, title;
    int age;
    char sex;

   public:
    Teacher(string, int, char, string, string, string);
    void show();
};

Teacher::Teacher(string _name, int _age, char _sex, string _address,
                 string _tel, string _title)
    : name(_name),
      age(_age),
      sex(_sex),
      address(_address),
      tel(_tel),
      title(_title) {}

void Teacher::show() {
    cout << "name: " << name << '\n';
    cout << "age: " << age << '\n';
    cout << "sex: " << sex << '\n';
    cout << "address: " << address << '\n';
    cout << "tel: " << tel << '\n';
    cout << "title: " << title << '\n';
}

class Cadre {
   protected:
    string name, address, tel, post;
    int age;
    char sex;

   public:
    Cadre(string, int, char, string, string, string);
};

Cadre::Cadre(string _name, int _age, char _sex, string _address, string _tel,
             string _post)
    : name(_name),
      age(_age),
      sex(_sex),
      address(_address),
      tel(_tel),
      post(_post) {}

class Teacher_Cadre : public Teacher, public Cadre {
    double wages;

   public:
    Teacher_Cadre(string, int, char, string, string, string, string, double);
    void show();
};

Teacher_Cadre::Teacher_Cadre(string _name, int _age, char _sex, string _address,
                             string _tel, string _title, string _post,
                             double _wages)
    : Teacher(_name, _age, _sex, _address, _tel, _title),
      Cadre(_name, _age, _sex, _address, _tel, _post),
      wages(_wages) {}

void Teacher_Cadre::show() {
    Teacher::show();
    cout << "post: " << post << '\n';
    cout << "wages: " << wages << '\n';
}

int main() {
    Teacher_Cadre tc("Li Ming", 30, 'M', "长安区", "18999998888", "教授",
                     "主任", 8000);
    tc.show();
    return 0;
}