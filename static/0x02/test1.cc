/* Author: fffzlfk */
#include <bits/stdc++.h>
using namespace std;

class People {
   protected:
    int age;
    double height, weight;
    static int num;

   public:
    People(int a, double h, double w) : age(a), height(h), weight(w) { num++; }
    void Eatting() { weight++; }
    void Sporting() { height++; }
    void Sleeping() {
        age++;
        height++;
        weight++;
    }
    void Show() {
        cout << "age = " << age << "岁" << endl;
        cout << "height = " << height << "厘米" << endl;
        cout << "weight = " << weight << "市斤" << endl;
    }
    static void ShowNum() { cout << "num = " << num << endl; }
};
int People::num = 0;

int main() {
    People p(20, 181, 140);
    p.Eatting();
    p.Sporting();
    p.Sleeping();
    p.Show();
    People::ShowNum();
    return 0;
}
