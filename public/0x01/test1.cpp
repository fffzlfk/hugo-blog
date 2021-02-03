/*************************************************************************
    > File Name: test1.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 18:28:24 2020
 ************************************************************************/

#include <iostream>
using namespace std;

int max(int a, int b, int c = 0) {
    int res = a > b ? a : b;
    res = res > c ? res : c;
    return res;
}

int main() {
    int a = 1, b = 4, c = 7;
    cout << max(a, b) << '\n';
    cout << max(a, b, c) << '\n';
    return 0;
}
