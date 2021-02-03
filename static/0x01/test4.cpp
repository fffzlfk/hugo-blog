/*************************************************************************
    > File Name: test4.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 18:50:07 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
template <typename T>
void my_sort(T nums[], int n) {
    sort(nums, nums + n);
}

int main() {
    int a[] = {3, 1, 5, 2, 10, 34, -18};
    double b[] = {0.1, 9.4, 2.5, 30.5, 3.14};
    my_sort(a, 7);
    my_sort(b, 5);
    for (const auto &e : a) cout << e << ' ';
    cout << '\n';

    for (const auto &e : b) cout << e << ' ';
    return 0;
}
