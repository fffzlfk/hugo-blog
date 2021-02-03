/*************************************************************************
    > File Name: test3.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Tue Sep 22 18:42:48 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;

void my_sort(int nums[], int n) { sort(nums, nums + n); }
void my_sort(double nums[], int n) { sort(nums, nums + n); }

int main() {
    int a[] = {3, 4, 1, 6, 23, 10, 22};
    double b[] = {9.9, 1.1, -2.4, 12.4, 2.45};
    my_sort(a, 7);
    my_sort(b, 6);
    for (const auto &e : a) cout << e << ' ';
    cout << endl;
    for (const auto &e : b) cout << e << ' ';
    cout << '\n';
    return 0;
}
