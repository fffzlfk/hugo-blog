---
title: AcWing寒假每日一题
date: 2021-01-10
draft: false
toc: true
tags:
  - C++
showInMenu: false
---

## Week 1

### 货仓选址

[题目链接](https://www.acwing.com/problem/content/description/106/)

#### 思路

绝对值不等式：$|a_1 - x| + |a_2 - x| + |a_3 - x| + ... + |a_n - x| \ge |a_n-a_1| + |a_{n-1}-a_{2}|+... $
结论：当n为奇数，x应在中位数；当n为偶数时，x应在中间两个数之间。

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 100005;
int a[N];
int n;
int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a + n);
    int ans = 0;
    for (int i = 0; i < n; i++) ans += abs(a[i]-a[n/2]);
    cout << ans;
    return 0;
}
```

### 数字三角形-DP

[题目链接](https://www.acwing.com/problem/content/900/)

#### 思路

从下到上，$ f[i][j] = max(f[i+1][j]+w[i][j], f[i+1][j+1]+w[i][j]) $

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 505;

int f[N][N], w[N][N];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> w[i][j];
    for (int i = 1; i <= n; i++)
        f[n][i] = w[n][i];
    for (int i = n-1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            f[i][j] = max(f[i+1][j]+w[i][j], f[i+1][j+1]+w[i][j]);
    cout << f[1][1];
    return 0;
}
```

#### 简化(等价变换)版代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 505;

int f[N][N];
int n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= i; j++)
            cin >> f[i][j];

    for (int i = n-1; i >= 1; i--)
        for (int j = 1; j <= i; j++)
            f[i][j] += max(f[i+1][j], f[i+1][j+1]);
    cout << f[1][1];
    return 0;
}
```

## Week 2

### 蛇形矩阵

[题目链接](https://www.acwing.com/problem/content/description/758/)

#### 代码

```cpp
#include <iostream>
using namespace std;

const int N = 105;

int n, m;
const int dx[]{-1, 0, 1, 0}, dy[]{0, 1, 0, -1};
int q[N][N];

int main() {
    cin >> n >> m;
    int x = 0, y = 0, d = 1;
    for (int i = 1; i <= n * m; i++) {
        q[x][y] = i;
        int a = x + dx[d], b = y + dy[d];
        if (a < 0 || a >= n || b < 0 || b >= m || q[a][b]) {
            d = (d + 1) % 4;
            a = x + dx[d], b = y + dy[d];
        }
        x = a, y = b;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++)
            cout << q[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
```

### 红与黑-Flood Fill算法

[题目链接](https://www.acwing.com/problem/content/description/1115/)

#### 思路

Flood-Fill
- BFS（最短距离）
```
while 队列为空
{
    取出队头t
    枚举t的4个邻格
    if 格子是陆地并且未开发
        标记为已被开发
        插入队列
}
```
- DFS（更方便）
```
dfs(x, y)
{
    将(x, y)标记为已开发
    枚举(x, y)的四个邻格
    if 格子是陆地并且未开发
        dfs该格子
}
```

#### 代码

##### BFS

```cpp
#include <iostream>
#include <queue>
#include <algorithm>
#define x first
#define y second

using namespace std;

typedef pair<int, int> PII;
const int N = 25;
int n, m;
char g[N][N];

int bfs(int sx, int sy) {
	queue<PII> Q;
	Q.push({sx, sy});
	g[sx][sy] = '#';
	int res = 0;
	const int dx[]{-1, 0, 1, 0}, dy[]{0, 1, 0, -1};
	while (!Q.empty()) {
		auto t = Q.front();
		Q.pop();
		res++;
		for (int i = 0; i < 4; i++) {
			int nx = t.x + dx[i], ny = t.y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '.') continue;
			g[nx][ny] = '#';
			Q.emplace(nx, ny);
		}
	}
	return res;
}

int main() {
	while (cin >> m >> n , n || m) {
		for (int i = 0; i < n; i++)
			cin >> g[i];
		int x, y;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (g[i][j] == '@') {
					x = i;
					y = j;
				}

		cout << bfs(x, y) << endl;
	}	
	return 0;
}
```

##### DFS

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 25;
char g[N][N];
int n, m;
const int dx[]{-1, 0, 1, 0}, dy[]{0, 1, 0, -1};
int dfs(int x, int y) {
    g[x][y] = '#';
    int res = 1;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i], ny = y + dy[i];
        if (nx < 0 || nx >= n || ny < 0 || ny >= m || g[nx][ny] != '.') continue;
        res += dfs(nx, ny);
    }
    return res;
}

int main() {
    while (cin >> m >> n, n || m) {
        int x, y;
        for (int i = 0; i < n; i++) {
            cin >> g[i];
            for (int j = 0; j < m; j++)
             if (g[i][j] == '@') {
                 x = i;
                 y = j;
             }
        }
        cout << dfs(x, y) << endl;
    }
    return 0;
}
```

### 回文平方

[题目链接](https://www.acwing.com/problem/content/1348/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>

using namespace std;

char get(int n) { return n <= 9 ? '0' + n : 'A' - 10 + n; }

string base(int n, int b) {
    string s = "";
    while (n) {
        s += get(n % b);
        n /= b;
    }
    reverse(s.begin(), s.end());
    return s;
}

bool check(const string &s) {
    for (int i = 0, j = s.length() - 1; i < s.length(); i++, j--)
        if (s[i] != s[j]) return false;
    return true;
}

int main() {
    int b;
    cin >> b;
    for (int i = 1; i <= 300; i++) {
        auto t = base(i * i, b);
        if (check(t)) {
            cout << base(i, b) << " " << t << endl;
        }
    }
    return 0;
}
```

### 剪绳子-浮点数二分

[题目链接](https://www.acwing.com/problem/content/682/)

#### 思路

二分
最优化->判定问题

- 情况1：可以[mid,  r]
- 情况2：不可以[l, mid)

保留k位小数：r-l < 1e-4

#### 代码

```cpp
#include <iostream>
using namespace std;

const int N = 100005;

int n, m;
int w[N];

bool check(double mid) {
    int cnt = 0;
    for (int i = 0; i < n; i++) cnt += w[i] / mid;
    return cnt >= m;
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> w[i];
    double l = 0.0, r = 1e9;
    for (int i = 0; i < 100; i++) { // while (r-l > 1e-4)
        double mid = (l + r) / 2;
        if (check(mid))
            l = mid;
        else
            r = mid;
    }
    printf("%.2f\n", l);
    return 0;
}
```

#### 扩展题

[题目链接](https://www.acwing.com/problem/content/792/)

```cpp
#include <iostream>

using namespace std;

double n;

bool check(double mid) {
    return mid*mid*mid < n;
}

int main() {
    cin >> n;
    double l = -22.0, r = 22.0;
    while (r - l > 1e-8) {
        double mid = (l+r) / 2;
        if (check(mid)) l = mid;
        else r = mid;
    }
    printf("%.6f\n", l);
    return 0;
}
```

### 分巧克力-整数二分

[题目链接](https://www.acwing.com/problem/content/1229/)

#### 思路

$ \sum_{i=0}^{n-1} \lfloor \frac {h_i} {mid} \rfloor \times \lfloor \frac{w_i}{mid} \rfloor\ge k $ 

- 成立：$[mid, r], l = mid$
- 不成立：$[l, mid-1], r = mid-1 $

#### 代码

```cpp
#include <iostream>
using namespace std;
using ll = long long;
const int N = 1e5+5;
int h[N], w[N];
int n, k;

bool check(int mid) {
    ll s = 0;
    for (int i = 0; i < n; i++) {
        s += 1LL * (h[i]/mid) * (w[i]/mid);
        if (s >= k) return true;
    }
    return false;
}

int main() {
    cin >> n >> k;
    for (int i = 0; i < n; i++)
        cin >> h[i] >> w[i];
    int l = 0, r = 1e5;
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
    cout << l << endl;
    return 0;
}
```

#### 二分模板

```cpp
int bsearch_1(int l, int r) {
    while (l < r) {
        int mid = l + r >> 1;
        if (check(mid)) r = mid;
        else l = mid+1;
    }
    return l
}

int bsearch_2(int l, int r) {
    while (l < r) {
        int mid = l + r + 1 >> 1;
        if (check(mid)) l = mid;
        else r = mid-1;
    }
}
```

#### 扩展题

- 数的范围

    [题目链接](https://www.acwing.com/problem/content/791/)

    ```cpp
    #include <iostream>
    #include <algorithm>
    using namespace std;
    int n, q;
    int a[100010];

    int main() {
        cin >> n >> q;
        for (int i = 0; i < n; i++)
            cin >> a[i];
        int k;
        while (q--) {
            cin >> k;
            int l = lower_bound(a, a+n, k)-a;
            int r = upper_bound(a, a+n, k)-a;
            printf("%d ", a[l]==k? l : -1);
            printf("%d\n", a[r-1]==k? r-1 : -1);
        }
        return 0;
    }
    ```
- 旋转数组的最小数字-不具有单调性，但具有二段性

    [题目链接](https://www.acwing.com/problem/content/description/20/)

    ```cpp
    class Solution {
    public:
        int findMin(vector<int>& nums) {
            if (nums.empty()) return -1;
            int n = nums.size();
            while (n > 1 && nums[0] == nums[n-1]) n--;
            if (nums[0] <= nums[n-1]) return nums[0];
            int l = 0, r = n-1;
            while (l < r) {
                int mid = l + r >> 1;
                if (nums[0] > nums[mid]) r = mid;
                else l = mid+1;
            }
            return nums[r];
        }
    };
    ```

### 校门外的树-区间合并

[题目链接](https://www.acwing.com/problem/content/424/)

#### 思路

先求出所有移动树木的操作的区间的并集，那么马路上剩余部分即为最终剩下树木的部分。

区间合并算法
- 将所有区间按左端点从小到大排序
- 从左到右遍历每个区间[L, R]
    - $ l_i \le R $， $R = max(R, r_i) $
    - $ l_i > R$, 则将[L, R] 存下来，L, R<- $ l_i, r_i $

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define y second
const int N = 105;
pair<int, int> seg[N];

int l, m;

int main() {
    cin >> l >> m;
    for (int i = 0; i < m; i++)
        cin >> seg[i].x >> seg[i].y;
    sort(seg, seg+m);
    int res = l + 1;
    int L = seg[0].x, R = seg[0].y;
    for (int i = 1; i < m; i++)
        if (seg[i].x <= R) R = max(R, seg[i].y);
        else {
            res -= R - L + 1;
            L = seg[i].x;
            R = seg[i].y;
        }
    res -= R - L + 1;
    cout << res << endl;
    return 0;
}
```

#### 扩展题-挤牛奶

[题目链接](https://www.acwing.com/problem/content/1343/)

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
#define x first
#define y second
const int N = 5005;
pair<int, int> seg[N];
int n;

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> seg[i].x >> seg[i].y;
    sort(seg, seg+n);
    int L = seg[0].x, R = seg[0].y;
    int a = 0, b = 0;
    for (int i = 1; i < n; i++)
        if (seg[i].x <= R) R = max(R, seg[i].y);
        else  {
            b = max(b, seg[i].x-R);
            a = max(a, R-L);
            L = seg[i].x;
            R = seg[i].y;
        }
    a = max(a, R-L);
    cout << a << " " << b << endl;
    return 0;
}
```

### 奖学金

[题目链接](https://www.acwing.com/problem/content/431/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;

int cnt = 0;
struct node {
    int id;
    int grades[3];
    
    int get_sum() const {
        int s = 0;
        for (int i = 0; i < 3; i++)
            s += grades[i];
        return s;
    }
    
    friend istream& operator>>(istream& in, node &a) {
        a.id = ++cnt;
        for (int i = 0; i < 3; i++)
            in >> a.grades[i];
        return in;
    }
    
    friend bool operator<(const node &a, const node &b) {
        int sa = a.get_sum(), sb = b.get_sum();
        if (sa != sb) return sa < sb;
        else if (a.grades[0] != b.grades[0]) return a.grades[0] < b.grades[0];
        else return a.id > b.id;
    }
};

int n;
priority_queue<node> Q;
int main() {
    cin >> n;
    node tmp;
    for (int i = 0; i < n; i++) {
        cin >> tmp;
        Q.push(tmp);
    }
    for (int i = 0; i < 5; i++) {
        auto t = Q.top();
        Q.pop();
        cout << t.id << " " << t.get_sum() << endl;
    }
    return 0;
}
```

## Week 3

### 翻硬币-递推

[题目链接](https://www.acwing.com/problem/content/1210/)

#### 思路

枚举递推：每一个操作是唯一确定的

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

string a, b;

void turn(int i) { a[i] == '*' ? a[i] = 'o' : a[i] = '*'; }

int main() {
    cin >> a >> b;
    int res = 0;
    for (int i = 0; i < a.length()-1; i++)
        if (a[i] != b[i]) {
            turn(i);
            turn(i+1);
            ++res;
        }
    cout << res << endl;
    return 0;
}
```

#### 扩展题-费解的开关

- **思路**
    - 枚举第一行的点击方法，共32种，完成第一行的点击后，固定第一行，
    - 从第一行开始递推，若达到第n行不全为0，说明这种点击方式不合法。
    - 在所有合法的点击方式中取点击次数最少的就是答案。
    - 对第一行的32次枚举涵盖了该问题的整个状态空间，因此该做法是正确的
    - 
    - 时间复杂度：`32*20*5*500 = 一百六十万`
    - `对第一行操作有32种可能 * 对前四行有20种操作可能 * 每一次操作都要改变5个灯的状态 * 最多读入的时候可能有500次light矩阵`
    - 最关键的两个性质
    - 每一个位置最多只会被点击一次
    - 如果固定了第一行，那么满足题意的点击方案最多只有一种
- **代码**
    ```cpp
    #include <iostream>
    #include <algorithm>
    #include <climits>
    #include <cstring>
    using namespace std;

    char s[5][5];

    void turn(int i, int j) {
        const int dx[]{0, -1, 0, 1, 0}, dy[]{0, 0, 1, 0, -1};
        for (int k = 0; k < 5; k++) {
            int nx = i + dx[k], ny = j + dy[k];
            if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) continue;
            s[nx][ny] ^= 1;
        }
    }

    int work() {
        int res = INT_MAX;
        for (int k = 0; k < 1 << 5; k++) {
            char back[5][5];
            memcpy(back, s, sizeof s);
            int cnt = 0;
            for (int j = 0; j < 5; j++) {
                if ((k >> j) & 1) {
                    turn(0, j);
                    ++cnt;
                }
            }
            for (int i = 0; i < 4; i++)
                for (int j = 0; j < 5; j++)
                    if (s[i][j] == '0') {
                        turn(i+1, j);
                        ++cnt;
                    }
            bool ok = true;
            for (int j = 0; j < 5; j++)
                if (s[4][j] == '0') ok = false;
            if (ok) res = min(res, cnt);
            memcpy(s, back, sizeof back);
        }
        return res <= 6 ? res : -1;
    }

    int main() {
        int n;
        cin >> n;
        while (n--) {
            for (int i = 0; i < 5; i++)
                cin >> s[i];
            cout << work() << endl;
        }
        return 0;
    }
    ```

### 找硬币

[题目链接](https://www.acwing.com/problem/content/1534/)

#### 哈希表做法$O(n)$

##### 思路

对于当前的元素t，查看之前集合中是否存在m-t，若存在则更新答案，否则添加到集合中。

##### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <climits>
#include <unordered_set>
using namespace std;

int n, m;
unordered_set<int> S;
int main() {
    cin >> n >> m;
    int v1 = INT_MAX, v2;
    int a, b;
    while (n--) {
        cin >> a;
        b = m - a;
        if (S.count(b)) {
            if (a > b) swap(a, b);
            if (v1 > a) {
                v1 = a;
                v2 = b;
            }
        } else S.insert(a);
    }
    printf(v1 == INT_MAX ? "No Solution" : "%d %d\n", v1, v2);
    return 0;
}
```

#### 双指针做法$O(nlogn)$

##### 思路

{{<notice note>}}
双指针算法：如果`i++`和`j--`单调性相反就能用双指针做法。
{{</notice>}}

$a[i]+a[j] \le m \ and \ j 最大$

##### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int n, m;
const int N = 1e5+5;
int a[N];
int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    sort(a, a+n);
    for (int i = 0, j = n-1; i < n; i++) {
        while (i < j && a[i] + a[j] > m) j--;
        if (i < j && a[i]+a[j] == m) {
            cout << a[i] << " " << a[j] << endl;
            return 0;
        }
    }
    cout << "No Solution";
    return 0;
}
```

### 十三号星期五

[题目链接](https://www.acwing.com/problem/content/1343/)

#### 思路

- 枚举每个月第一天距离1900-1-1过了多少天days
- 星期：$(days+12)\  mod \ 7 $

#### 代码

```cpp
#include <iostream>
using namespace std;

const int month[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
int n;
int weekdays[7];

int main() {
    cin >> n;
    int days = 0;
    for (int year = 1900; year < 1900+n; year++) {
        for (int i = 1; i <= 12; i++) {
            weekdays[(days + 12) % 7]++;
            days += month[i];
            if (i == 2 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0)) days++; 
        }
    }
    for (int i = 5, j = 0; j < 7; i = (i+1) % 7, j++)
        cout << weekdays[i] << " ";
    return 0;
}
```

### 平方矩阵 II

[题目链接](https://www.acwing.com/problem/content/756/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

int n;

int main() {
    while (cin >> n, n) {
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++)
                cout << abs(j-i) + 1 << ' ';
            cout << '\n';
        }
        cout << endl;
    }
    return 0;
}
```

#### Longest-increasing-subsequence

[题目链接](https://leetcode-cn.com/problems/longest-increasing-subsequence/)

##### 思路

- dp[i]: 长度为i的LIS的最后一个元素的最小值
- eg:[0,3,1,6,2,2,7] for each x:
    - 0, dp = [0]
    - 3, dp = [0, 3]
    - 1, dp = [0, 1]
    - 6, dp = [0, 1, 6]
    - 2, dp = [0, 1, 2]
    - 2, dp = [0, 1, 2]
    - 7, dp = [0, 1, 2, 7]
- ans = len(dp)
##### 代码

```python
class Solution:
    def lengthOfLIS(self, nums: List[int]) -> int:
        dp = []
        for x in nums:
            i = bisect_left(dp, x)
            if i == len(dp):
                dp.append(x)
            else:
                dp[i] = x
        return len(dp)
```

### 棋盘挑战-八皇后问题

[题目链接](https://www.acwing.com/problem/content/1434/)

#### 思路
    
- 如何判断某些位置能不能填：对角线用截距编号
    - dg: y=x+b, b = y-x+n
    - udg: y=-x+b, b = y+x

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 15;

int path[N], col[N], dg[2*N], udg[2*N];

int n, ans;

void dfs(int x) {
    if (x > n) {
        ans++;
        if (ans <= 3) {
            for (int i = 1; i <= n; i++)
                cout << path[i] << ' ';
            cout << '\n';
        }
    }
    for (int y = 1; y <= n; y++) {
        if (!col[y] && !dg[y-x+n] && !udg[y+x]) {
            path[x] = y;
            col[y] = dg[y-x+n] = udg[y+x] = true;
            dfs(x+1);
            col[y] = dg[y-x+n] = udg[y+x] = false;
            // path[x] = 0;
        }
    }
}

int main() {
    cin >> n;
    dfs(1);
    cout << ans;
    return 0;
}
```

#### 扩展题-解数独

[题目链接](https://leetcode-cn.com/problems/sudoku-solver/)

```cpp
class Solution {
public:
    vector<pair<int, int>> P;
    bool check(const vector<vector<char>>& board, int r, int c, char n) {
        for (int i = 0; i < 9; i++)
            if (board[r][i] == n || board[i][c] == n) return false;
        r = r / 3 * 3;
        c = c / 3 * 3;
        for (int i = r; i < r + 3; i++)
            for (int j = c; j < c + 3; j++)
                if (board[i][j] == n) return false;
        return true;
    }
    bool dfs(vector<vector<char>>& board, int idx) {
        if (idx == (int)P.size()) return true;
        int r = P[idx].first, c = P[idx].second;
        for (int i = 1; i <= 9; i++)
            if (check(board, r, c, i+'0')) {
                board[r][c] = i+'0';
                if (dfs(board, idx+1)) return true;
                board[r][c] = '.';
            }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] == '.')
                    P.emplace_back(i, j);
        dfs(board, 0);
    }
};
```

### 货币系统-完全背包

[题目链接](https://www.acwing.com/problem/content/description/1373/)

#### 思路

{{<image src="https://img-blog.csdnimg.cn/20210122225542349.png?x-oss-process=image/watermark,type_ZmFuZ3poZW5naGVpdGk,shadow_10,text_aHR0cHM6Ly9ibG9nLmNzZG4ubmV0L3dlaXhpbl80NTYyOTI4NQ==,size_16,color_FFFFFF,t_70" position="center" style="zoom: 80% ;">}}

#### 代码

```cpp
#include <iostream>
using namespace std;
using ll = long long;
const int N = 30, M = 10005;
ll f[N][M];
int n, m;
int w[N];
int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        cin >> w[i];
    f[0][0] = 1;
    for (int i = 1; i <= n; i++)
        for (int j = 0; j <= m; j++)
            for (int k = 0; k * w[i] <= j; k++)
                f[i][j] += f[i-1][j-k*w[i]];
    cout << f[n][m] << endl;
    return 0;
}
```

#### 时间优化

1. $ f[i][j] = f[i-1][j]+f[i-1][j-w[i]]+f[i-1][j-2w[i]]+...+f[i-1][j-kw[i]] $
2. $ f[i][j-v] = f[i-1][j-w[i]]+f[i-1][j-2w[i]]+...+f[i-1][j-kw[i]] $
3. 由1-2得：$ f[i][j] = f[i-1][j]+f[i][j-v] $

```cpp
#include <iostream>
using namespace std;
using ll = long long;
const int N = 30, M = 10005;
ll f[N][M];
int n, m;
int main() {
    cin >> n >> m;
    f[0][0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = 0; j <= m; j++) {
            f[i][j] = f[i-1][j];
            if (j >= v) f[i][j] += f[i][j-v];
        }
    }
    cout << f[n][m] << endl;
    return 0;
}
```
#### 空间优化

```cpp
#include <iostream>
using namespace std;
using ll = long long;
const int N = 30, M = 10005;
ll f[M];
int n, m;
int main() {
    cin >> n >> m;
    f[0] = 1;
    for (int i = 1; i <= n; i++) {
        int v;
        cin >> v;
        for (int j = v; j <= m; j++) {
            f[j] += f[j-v];
            // f[i][j] = f[i-1][j] + f[i][j-v]
        }
    }
    cout << f[m] << endl;
    return 0;
}
```

### 阶乘

[题目链接](https://www.acwing.com/problem/content/1383/)

#### 思路

- $ n! = 2^{\alpha}*5^{\beta}*x $
- $ ans = \frac{n!}{10^k}\ mod\ 10=$

我们进行观察，因为0只可能由2的倍数和5的倍数相乘得到，所以在进行乘法的过程中，我们将2和5的倍数给清理掉，这样就保证了不会出现0，然后我们控制其范围，每次相乘取其个位，因为个位肯定是非零元素，十位以后的数字完全没有必要保留下来，最后，我们将多处理的2或者5重新乘回去再取余即可

#### 代码

```cpp
#include <iostream>
using namespace std;

int main() {
    int n;
    cin >> n;
    int d2 = 0, d5 = 0;
    int ans = 1;
    for (int i = 2; i <= n; i++) {
        int x = i;
        while (x % 2 == 0) x /= 2, d2++;
        while (x % 5 == 0) x /= 5, d5++;
        ans = ans * x % 10;
    }
    for (int i = 0; i < d2-d5; i++)
        ans = ans * 2 % 10;
    cout << ans;
    return 0;
}
```

## Week 4

### 滑雪场设计-枚举

#### 思路

- 最优解中，所有的高度都在$[0, 100]$之间
- 只需枚举所有可能的区间

#### 代码

```cpp
#include <iostream>
#include <climits>
using namespace std;
const int N = 1005;
int a[N];

int main() {
    int n;
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int ans = INT_MAX;
    for (int l = 0; l <= 100-17; l++) {
        int r = l+17, cost = 0;
        for (int i = 0; i < n; i++)
            if (a[i] < l) cost += (l-a[i])*(l-a[i]);
            else if (a[i] > r) cost += (a[i]-r)*(a[i]-r);
        ans = min(ans, cost);
    }
    cout << ans;
    return 0;
}
```

### 整数集合划分-贪心

[题目链接](https://www.acwing.com/activity/content/problem/content/3449/1/)


#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int a[100005], res;
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	sort(a, a + n);
	for (int i = 0; i < n; i++) {
		if (i >= n >> 1) res += a[i];
		else res -= a[i];
	}
	cout << n % 2 << ' ' << res;
	return 0;
}
```

#### 扩展题-双向搜索

[题目链接](https://www.acwing.com/problem/content/description/173/)

- 思路
    - 先搜索前`N/2`个物品可以凑出来的所有重量，存到数组中去
    - 对所有重量排序，判重
    - 在搜索后一半物品可以凑出来的所有重量`y`，在前一半物品搜索出来的重量二分出一个`y`，使得`x+y<=w`, `x+y`最大

- 优化
    - 从大到小枚举所有重量，使得搜索到的和更快达到目标
    - 均衡两次搜索时间


```cpp
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;
const int N = 46;
int n, w, g[N], k, cnt, wgt[1 << (23 + 2)];
void dfs_1(int x, int s) {
	if (x == k) {
		wgt[cnt++] = s;
		return;
	}
	if (s * 1ll + g[x] <= w) dfs_1(x + 1, s + g[x]);
	dfs_1(x + 1, s);
}
int ans;
void dfs_2(int x, int s) {
	if (x == n) {
		int l = 0, r = cnt - 1;
		while (l < r) {
			int mid = l + r + 1 >> 1;
			if (s * 1ll + wgt[mid] <= w) l = mid;
			else r = mid - 1;
		}
		if (s * 1ll + wgt[l] <= w) ans = max(ans, s + wgt[l]);
		return;
	}
	if (s * 1ll + g[x] <= w) dfs_2(x + 1, s + g[x]);
	dfs_2(x + 1, s);
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	scanf("%d%d", &w, &n);
	for (int i = 0; i < n; i++) scanf("%d", &g[i]);
	sort(g, g + n, greater<int>());
	k = n / 2 + 2;
	dfs_1(0, 0);
	sort(wgt, wgt + cnt);
	cnt = unique(wgt, wgt + cnt) - wgt;
	dfs_2(k, 0);
	cout << ans;
	return 0;
}
```

### 合唱队形-LIS

[题目链接](https://www.acwing.com/problem/content/description/484/)

#### 思路

- `f[i]`: 从前往后，以`a[i]`结尾的最长上升子序列的长度
- `g[i]`: 从后往前，以`a[i]`结尾的最长上升子序列的长度
- $ ans = n - max(f[i]+g[i]) + 1$

#### 代码

$ n^2 $

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 105;
int n, a[N];
int f[N], g[N];

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> a[i];
    
    for (int i = 1; i <= n; i++) {
        f[i] = 1;
        for (int j = 1; j < i; j++)
            if (a[i] > a[j]) f[i] = max(f[i], f[j]+1);
    }
    
    for (int i = n; i >= 1; i--) {
        g[i] = 1;
        for (int j = n; j > i; j--)
            if (a[i] > a[j]) g[i] = max(g[i], g[j]+1);
    }
    int ans = 0;
    for (int k = 1; k <= n; k++) ans = max(ans, f[k] + g[k]);
    
    cout << n - ans + 1;
    return 0;

```

$ nlogn $

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 105;
int f[N], g[N], a[N], n;
int len1[N], len2[N];
int main() {
    cin >> n;
    for (int i = 0; i < n; i++) cin >> a[i];
    int cnt = 0;
    for (int i = 0; i < n; i++) {
        auto it = lower_bound(f, f+cnt, a[i])-f;
        if (it == cnt) f[cnt++] = a[i];
        else f[it] = a[i];
        len1[i] = cnt;
    }
    cnt = 0;
    for (int i = n-1; i >= 0; i--) {
        auto it = lower_bound(g, g+cnt, a[i])-g;
        if (it == cnt) g[cnt++] = a[i];
        else g[it] = a[i];
        len2[i] = cnt;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) ans = max(ans, len1[i]+len2[i]);
    cout << n - ans + 1;
    return 0;
}
```

### 火星人-排列

#### 思路

实现next_permutation()

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 10005;
int n, m, a[N];

int main() {
    cin >> n >> m;
    for (int i = 0; i < n; i++) cin >> a[i];
    while (m--) {
        int k = n-1;
        while (a[k-1] > a[k]) k--;
        k--;
        int t = k;
        while (t < n-1 && a[t+1] > a[k]) t++;
        swap(a[t], a[k]);
        reverse(a+k+1, a+n);
    }
    for (int i = 0; i < n; i++) cout << a[i] << ' ';
    return 0;
}
```

### 星空之夜-Flood-fill

#### 思路

- 判断形状是否相似
    - 哈希：两两之间的距离之和

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
using P = pair<int, int>;
#define x first
#define y second

const int N = 105;
P c[N*N];
int cnt;
char g[N][N];
int n, m;

inline double get_dist(P a, P b) {
    return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double get_hash() {
    double s = 0;
    for (int i = 0; i < cnt; i++)
        for (int j = i+1; j < cnt; j++)
            s += get_dist(c[i], c[j]);
    return s;
}

char get_id(double d) {
    static double hash[30];
    static int idx = 0;
    for (int i = 0; i < idx; i++) {
        if (fabs(hash[i] - d) < 1e-8)
            return 'a' + i;
    }
    hash[idx++] = d;
    return 'a' + idx - 1;
}

void dfs(int i, int j) {
    g[i][j] = '0';
    c[cnt++] = {i, j};
    for (int x = i-1; x <= i+1; x++)
        for (int y = j-1; y <= j+1; y++) {
            if (x < 0 || x >= n || y < 0 || y >= m || g[x][y] == '0') continue;
            dfs(x, y);
        }
}

int main() {
    cin >> m >> n;
    for (int i = 0; i < n; i++) cin >> g[i];
    for (int i = 0; i < n; i++)
        for (int j = 0; j < m; j++) {
            if (g[i][j] == '1') {
                cnt = 0;
                dfs(i, j);
                auto d = get_hash();
                auto id = get_id(d);
                for (int k = 0; k < cnt; k++) g[c[k].x][c[k].y] = id;
            }
        }
    for (int i = 0; i < n; i++) cout << g[i] << endl;
    return 0;
}
```

### 摘花生-DP

[题目链接](https://www.acwing.com/problem/content/description/1017/)

#### 思路

1. 状态表示
    - 集合：定义f[i][j]为从(1, 1)到达(i, j)的所有方案
    - 属性：最大值
2. 状态转移
    - (i, j)从(i-1, j)即上方过来
    - (i, j)从(i, j-1)即左方过来
3. 空间压缩
    - f[i][j]只需要用到这一层和上一层的f元素，所以可以压缩成滚动数组。在此之上，还可以直接压缩成一维数组。

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;

const int N = 105;
int f[N];
int n, m, t;

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> n >> m;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= m; j++) {
                cin >> t;
                f[j] = max(f[j], f[j-1]) + t;
            }
        cout << f[m] << endl;
        memset(f, 0, sizeof f);
    }
}
```

### 最大的和-最大子矩形

#### 思路

- 前缀和数组`A[i][j]`表示 $ \sum_{i=1}^{n}{a[i][j]} $
- 枚举矩形上下边界
- 求最大连续子序列和

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 105;
int a[N][N], n;
int main() {
    cin >> n;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++) {
            cin >> a[i][j];
            a[i][j] += a[i-1][j];
        }
    int ans = INT_MIN;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            int s = 0;
            for (int k = 1; k <= n; k++) {
                // s = (s < 0 ? a[j][k]-a[i-1][k] : a[j][k]-a[i-1][k] + s);
                s = max(s, 0) + a[j][k] - a[i-1][k];
                ans = max(ans, s);
            }
        }
    }
    cout << ans;
    return 0;
}
```

### 最大的和-线性DP

[题目链接](https://www.acwing.com/problem/content/1053/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <climits>
using namespace std;
const int N = 50005;
int n, a[N], f[N], g[N]; // f[i]: 1~i最大连续子段和，g[i]:n~i最大连续子段和

int main() {
    int T;
    scanf("%d", &T);
    while (T--) {
        scanf("%d", &n);
        fill(f, f+n+2, INT_MIN);
        fill(g, g+n+2, INT_MIN);
        for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            s = max(s, 0) + a[i];
            f[i] = max(f[i-1], s);
        }
        s = 0;
        for (int i = n; i >= 1; i--) {
            s = max(s, 0) + a[i];
            g[i] = max(g[i+1], s);
        }
        int ans = INT_MIN;
        for (int i = 1; i < n; i++)
            ans = max(ans, f[i] + g[i+1]);
        cout << ans << endl;
    }
    return 0;
}
```

### 最大异或对-trie

[题目链接](https://www.acwing.com/problem/content/submission/145/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;

const int N = 1e5+5, M = 3e6+5;
int a[N], son[M][2], idx, n;

void insert(int x) {
    int p = 0;
    for (int i = 30; ~i; i--) {
        int t = x >> i & 1;
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
}

int query(int x) {
    int p = 0, res = 0;
    for (int i = 30; ~i; i--) {
        int t = x >> i & 1;
        if (son[p][!t]) {
            res += 1 << i;
            p = son[p][!t];
        } else {
            p = son[p][t];
        }
    }
    return res;
}

int main() {
    cin >> n;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
        insert(a[i]);
        ans = max(ans, query(a[i]));
    }
    cout << ans;
    return 0;
}
```

#### 牛亦或-trie+前缀和

[题目链接](https://www.acwing.com/problem/content/description/1416/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5, M = 2e6+5;
int son[M][2], a[N], id[M], idx, n;

void insert(int x, int k) {
    int p = 0;
    for (int i = 20; ~i; i--) {
        int t = x >> i & 1;
        if (!son[p][t]) son[p][t] = ++idx;
        p = son[p][t];
    }
    id[p] = k;
}

int query(int x) {
    int p = 0;
    for (int i = 20; ~i; i--) {
        int t = x >> i & 1;
        if (son[p][!t]) {
            p = son[p][!t];
        } else {
            p = son[p][t];
        }
    }
    return id[p];
}

int main() {
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] ^= a[i-1];
    }
    insert(0, 0);
    int ans = -1, l, r;
    for (int i = 1; i <= n; i++) {
        int k = query(a[i]);
        int s = a[i] ^ a[k];
        if (s > ans) {
            ans = s;
            l = k + 1, r = i;
        }
        insert(a[i], i);
    }
    cout << ans << " " << l << ' ' << r << endl;
    return 0;
}
```

## Week 5

### 开心的金明-01背包

[题目链接](https://www.acwing.com/problem/content/428/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
int f[30005];
int n, m;

int main() {
    cin >> n >> m;
    int v, w;
    for (int i = 0; i < m; i++) {
        cin >> v >> w;
        for (int j = n; j >= v; j--)
            f[j] = max(f[j], f[j-v]+w*v);
    }
    cout << f[n] << endl;
    return 0;
}
```

### K倍区间-前缀和

[题目链接](https://www.acwing.com/problem/content/1232/)

#### 思路

求区间和，可以通过前缀和来求出。`sum[r]−sum[l−1]`就是区间`[l,r]`的和。如果区间`[l,r]`的和是k的倍数则有`(sum[r]−sum[l−1])`，即`sum[r]`。因此，我们可以得到一个结论，对前缀和取模之后，两个相等的前缀和就能组成一个k倍区间。

有了这个结论之后，我们就可以使用两层for循环来计数k倍区间的个数，但是由于数据比较大，我们不能这样做。那么我们能不能在计算前缀和的过程中同时来统计k倍区间的个数呢？当然可以。我们可以用一个数组cnt，规定`cnt[i]`表示当前位置之前，前缀和取模后等于i的个数，以后每出现一次前缀和（取模后）和它相等，那么k倍区间就加上`cnt[sum[i]]`，然后`cnt[sum[i]]++`。这样似乎不容易理解，我们用样例举个例子。

对于数列 1 2 3 4 5，k = 2

对前1个数的和模k后为1，在此之前有0个前缀和取模后为1，总个数+0

对前2个数的和模k后为1，在此之前有1个前缀和取模后为1，总个数+1

对前3个数的和模k后为0，在此之前有0个前缀和取模后为0, 总个数+0

对前4个数的和模k后为0，在此之前有1个前缀和取模后为0，总个数+1

对前5个数的和模k后为1，在此之前有2个前缀和取模后为1，总个数+2

但是我们还忽略了一点，就是我们这样做我们少计算了区间·`[0,i]`构成的k倍区间，其个数为`cnt[0]`。


#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1e5+5;
int a[N], n, k, cnt[N];

int main() {
    cin >> n >> k;
    long ans = 0;
    for (int i = 1; i <= n; i++) {
        cin >> a[i];
        a[i] = (a[i] + a[i-1]) % k;
        ans += cnt[a[i]];
        cnt[a[i]]++;
    }
    cout << ans + cnt[0];
    return 0;
}
```

### 数独检查-模拟

[题目链接](https://www.acwing.com/problem/content/description/705/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
const int N = 7;
int n, m;
int g[N*N][N*N];
bool st[N*N];

bool check_row() {
    for (int i = 0; i < m; i++) {
        memset(st, false, sizeof st);
        for (int j = 0; j < m; j++) {
            int t = g[i][j];
            if (t < 1 || t > m) return false;
            if (st[t]) return false;
            st[t] = true;
        }
    }
    return true;
}

bool check_col() {
    for (int i = 0; i < m; i++) {
        memset(st, false, sizeof st);
        for (int j = 0; j < m; j++) {
            int t = g[j][i];
            if (t < 1 || t > m) return false;
            if (st[t]) return false;
            st[t] = true;
        }
    }
    return true;
}

bool check_cell() {
    for (int i = 0; i < m; i += n)
        for (int j = 0; j < m; j += n) {
            memset(st, false, sizeof st);
            for (int dx = 0; dx < n; dx++)
                for (int dy = 0; dy < n; dy++) {
                    int t = g[i+dx][j+dy];
                    if (t < 1 || t > m) return false;
                    if (st[t]) return false;
                    st[t] = true;
                }
        }
    return true;
}

int main() {
    int T;
    cin >> T;
    for (int t = 1; t <= T; t++) {
        cin >> n;
        m = n * n;
        for (int i = 0; i < m; i++)
            for (int j = 0; j < m; j++) cin >> g[i][j];
        
        printf(check_row() && check_col() && check_cell() ? "Case #%d: Yes\n" : "Case #%d: No\n", t);
    }
    
    return 0;
}
```

### 最长公共子序列-LCS

[题目链接](https://www.acwing.com/problem/content/899/)

#### 思路

{{<image src="https://i.postimg.cc/y8BJBtnM/2.jpg" position="center" style="zoom: 50% ;">}}

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
const int N = 1005;
int n, m, f[N][N];
char a[N], b[N];

int main() {
    cin >> n >> m >> a + 1 >> b + 1;
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= m; j++)
            if (a[i] == b[j]) f[i][j] = f[i-1][j-1] + 1;
            else f[i][j] = max(f[i-1][j], f[i][j-1]);
    cout << f[n][m];
    return 0;
}
```

### 数独简单版-数独

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
char g[10][10];
bool row[10][10], col[10][10], cell[3][3][10];

bool dfs(int x, int y) {
    if (y == 9) {
        x++, y = 0;
    }
    if (x == 9) {
        for (int i = 0; i < 9; i++) cout << g[i] << endl;
        return true;
    }
    if (g[x][y] != '.') return dfs(x, y+1);
    for (int i = 1; i <= 9; i++) {
        if (!row[x][i] && !col[y][i] && !cell[x/3][y/3][i]) {
            g[x][y] = i + '0';
            row[x][i] = col[y][i] = cell[x/3][y/3][i] = true;
            if (dfs(x, y+1)) return true;
            row[x][i] = col[y][i] = cell[x/3][y/3][i] = false;
            g[x][y] = '.';
        }
    }
    return false;
}

int main() {
    for (int i = 0; i < 9; i++) {
        cin >> g[i];
        for (int j = 0; j < 9; j++)
            if (g[i][j] != '.') {
                int t = g[i][j] - '0';
                row[i][t] = col[j][t] = cell[i/3][j/3][t] = true;
            }
    }
    dfs(0, 0);
}
```

### 献给阿尔吉侬的花束-BFS

[题目链接](https://www.acwing.com/problem/content/description/1103/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>
using namespace std;
const int N = 205;
const int dx[]{-1, 0, 1, 0}, dy[]{0, 1, 0, -1};

char g[N][N];
int dist[N][N];
int r, c;

bool bfs(int x, int y) {
    memset(dist, 0, sizeof dist);
    queue<pair<int, int>> Q;
    Q.push({x, y});
    while (!Q.empty()) {
        auto [tx, ty] = Q.front();
        Q.pop();
        if (g[tx][ty] == 'E') {
            cout << dist[tx][ty] << endl;
            return true;
        }
        for (int i = 0; i < 4; i++) {
            int nx = tx + dx[i], ny = ty + dy[i];
            if (nx < 0 || nx >= r || ny < 0 || ny >= c ||  g[nx][ny] == '#') continue;
            Q.push({nx, ny});
            if (g[nx][ny] != 'E')
                g[nx][ny] = '#';
            dist[nx][ny] = dist[tx][ty] + 1;
        }
    }
    cout << "oop!" << endl;
    return false;
}

int main() {
    int T;
    cin >> T;
    while (T--) {
        cin >> r >> c;
        for (int i = 0; i < r; i++) cin >> g[i];
        bool is_break = false;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++)
                if (g[i][j] == 'S') {
                    bfs(i, j);
                    is_break = true;
                    break;
                }
            if (is_break) break;
        }
    }
    return 0;
}
```

### a^b-位运算

[题目链接](https://www.acwing.com/problem/content/91/)

#### 代码

```cpp
#include <iostream>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    ll a, b, p;
    cin >> a >> b >> p;
    ll res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    cout << res % p << endl;
    return 0;
}
```