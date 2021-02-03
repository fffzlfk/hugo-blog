/* Author: fffzlfk */
#include <bits/stdc++.h>
using namespace std;

class Student {
    int id, score;

   public:
    Student(int _id, int _score) : id(_id), score(_score) {}
    int getId() { return id; }
    int getScore() { return score; }
    void show() { cout << getId() << ' ' << getScore() << '\n'; }
};

void max(Student *stu) {
    Student max_stu(0, 0);
    int max_score = 0;
    for (Student *p = stu; p < stu + 5; p++)
        if (p->getScore() > max_score) {
            max_score = p->getScore();
            max_stu = *p;
        }
    cout << "the highest score student is =" << max_stu.getId() << '\n';
}

int main() {
    Student stus[]{{1801, 90}, {1802, 91}, {1803, 78}, {1804, 80}, {1805, 95}};
    Student *p = &stus[0];
    for (; p < stus + 5; p += 2) p->show();
    max(stus);
    return 0;
}
