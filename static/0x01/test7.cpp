/*************************************************************************
    > File Name: test7.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 19:13:45 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

class Cuboid {
   private:
    double length[3], width[3], height[3];

   public:
    Cuboid();
    vector<double> getVolume();
    void printVolume();
};

Cuboid::Cuboid() {
    cout << "依次输入3个长方体的长宽高" << '\n';
    for (int i = 0; i < 3; i++) cin >> length[i] >> width[i] >> height[i];
}

vector<double> Cuboid::getVolume() {
    vector<double> volumes(3);
    for (int i = 0; i < 3; i++) volumes[i] = length[i] * width[i] * height[i];
    return volumes;
}

void Cuboid::printVolume() {
    for (cosnt auto &e : getVolume()) cout << e << ' ';
}

int main() {
    Cuboid cuboid;
    cuboid.printVolume();
    return 0;
}
