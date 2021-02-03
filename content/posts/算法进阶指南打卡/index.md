---
title: 算法进阶指南打卡
date: 2020-09-22T12:45:22+08:00
draft: false
hideLastModified: true
# cover: "img/trie_tree.jpg"
# useRealtiveCover: true
keepImageRatio: true
summary: "蓝书"
showInMenu: false
---


### 位运算
#### a^b
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;

ll fast_pow(ll a, ll b, ll p) {
    ll ans = 1;
    while (b) {
        if (b & 1) ans = ans * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return ans % p;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << fast_pow(a, b, p) << '\n';
    return 0;
}
```

#### a\*b
```cpp
#include <bits/stdc++.h>
using namespace std;
using ll = long long;
ll mul(ll a, ll b, ll p) {
    ll ans = 0;
    while (b) {
        if (b & 1) ans = (ans + a) % p;
        a = a * 2 % p;
        b >>= 1;
    }
    return ans;
}

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    cout << mul(a, b, p) << '\n';
    return 0;
}

```
#### hamilton
```cpp
/*************************************************************************
    > File Name: hamilton.cpp
    > Author: fffzlfk
    > Mail: fffzlfk@qq.com
    > Created Time: Wed Sep 23 10:29:48 2020
 ************************************************************************/

#include <bits/stdc++.h>
using namespace std;
int w[20][20];
int f[1 << 20][20];
int n;
int hamilton() {
    memset(f, 0x3f, sizeof(f));
    f[1][0] = 0;
    for (int i = 1; i < 1 << n; i++)
        for (int j = 0; j < n; j++)
            if (i >> j & 1)
                for (int k = 0; k < n; k++)
                    if (i >> k & 1)
                        f[i][j] = min(f[i][j], f[i ^ 1 << j][k] + w[k][j]);
    return f[(1 << n) - 1][n - 1];
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++) cin >> w[i][j];
    cout << hamilton() << '\n';
    return 0;
}
```

### 递归

#### 递归实现指数型枚举
```cpp
#include <bits/stdc++.h>
using namespace std;
int n;
vector<int> tmp;
void dfs(int idx) {
    if (idx == n + 1) {
        for (const auto &e : tmp) cout << e << ' ';
        cout << '\n';
        return;
    }
    tmp.emplace_back(idx);
    dfs(idx + 1);
    tmp.pop_back();
    dfs(idx + 1);
}

int main() {
    cin >> n;
    dfs(1);
    return 0;
}
```

#### 递归实现组合型枚举
```cpp
#include <bits/stdc++.h>
using namespace std;
int n, m;
vector<int> tmp;
void dfs(int idx) {
    if (tmp.size() > m || tmp.size() + (n - idx + 1) < m) return;
    if (idx == n + 1) {
        for (const auto &e : tmp) cout << e << ' ';
        cout << '\n';
        return;
    }
    tmp.emplace_back(idx);
    dfs(idx + 1);
    tmp.pop_back();
    dfs(idx + 1);
}

int main() {
    cin >> n >> m;
    dfs(1);
    return 0;
}
```

### 二分

#### 二分查找左右边界
```cpp
#include <bits/stdc++.h>
using namespace std;
int get_right(vector<int> a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + r >> 1;
        if (a[mid] >= x)
            r = mid;
        else
            l = mid + 1;
    }
    return l;
}

int get_left(vector<int> a, int x) {
    int l = 0, r = (int)a.size();
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (a[mid] <= x)
            l = mid;
        else
            r = mid - 1;
    }
    return l;
}

int main() {
    vector<int> a = {1, 3, 5, 7, 9, 19};
    cout << get_left(a, 6) << '\n';
    cout << get_right(a, 6) << '\n';
    return 0;
}
```

#### 三分法求极值
```cpp
#include <bits/stdc++.h>
using namespace std;
vector<double> a;
int n;
double l, r;

double cal(double x) {
    double res = 0.0;
    for (int i = n; i >= 0; i--) res += a[i] * pow(x, i);
    return res;
}

int main() {
    cin >> n >> l >> r;
    a.resize(n + 1);
    for (int i = n; i >= 0; i--) cin >> a[i];
    while (fabs(l - r) >= 1e-6) {
        double mid = (l + r) / 2;
        if (cal(mid - 1e-6) < cal(mid + 1e-6))
            l = mid;
        else
            r = mid;
    }
    printf("%.5lf\n", r);
    return 0;
}
```

#### 二分答案转换为判定
>有n本书排成一行，已知第i本书的厚度是$A_i$。把它们分成连续的M组，使得T最小化，其中T表示厚度之和最大的一组的厚度。

```cpp
#include <bits/stdc++.h>
using namespace std;

int n, m;
int a[1005];
bool check(int size) {
    int tot = 0, rest = size;
    for (int i = 0; i < n; i++) {
        if (res >= a[i])
            res -= a[i];
        else {
            tot++;
            res = size - a[i];
        }
    }
	return tol <= m;
}

int main() {
    cin >> n >> m;
    long long sum_of_ai = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        sum_of_ai += a[i];
    }
    int l = 0, r = sum_of_ai;
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid))
            r = mid;
        else
            l = mid + 1;
    }
    cout << l << '\n';
    return 0;
}
```
