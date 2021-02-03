---
title: LeetCode杂题2
date: 2020-10-04T12:25:11+08:00
draft: false
hideLastModified: true
summaryImage: "img/lc.jpeg"
keepImageRatio: true
summary: "杂题记录2"
showInMenu: false
---

### 特殊数组的特征值
给你一个非负整数数组 nums 。如果存在一个数 x ，使得 nums 中恰好有 x 个元素 大于或者等于 x ，那么就称 nums 是一个 特殊数组 ，而 x 是该数组的 特征值 。

>注意： x 不必 是 nums 的中的元素。

如果数组 nums 是一个 特殊数组 ，请返回它的特征值 x 。否则，返回 -1 。可以证明的是，如果 nums 是特殊数组，那么其特征值 x 是 唯一的 。

>示例 1:  
输入：nums = [3,5]  
输出：2  
解释：有 2 个元素（3 和 5）大于或等于 2 。  

>示例 2：  
输入：nums = [0,0]  
输出：-1  
解释：没有满足题目要求的特殊数组，故而也不存在特征值 x 。  
如果 x = 0，应该有 0 个元素 >= x，但实际有 2 个。  
如果 x = 1，应该有 1 个元素 >= x，但实际有 0 个。  
如果 x = 2，应该有 2 个元素 >= x，但实际有 0 个。  
x 不能取更大的值，因为 nums 中只有两个元素。  

>示例 3：  
输入：nums = [0,4,3,0,4]  
输出：3  
解释：有 3 个元素大于或等于 3 。  

>示例 4：  
输入：nums = [3,6,7,7,0]  
输出：-1  


> 提示：  
   1 <= nums.length <= 100  
   0 <= nums[i] <= 1000

#### Code

```cpp
class Solution {
public:
    int specialArray(vector<int>& nums) {
        for (int i = 0; i < 1001; i++) {
            int cnt = 0;
            for (const auto &e : nums) {
                if (i <= e) ++cnt;
            }
            if (cnt == i)
                return i;
        }
        return -1;
    }
};
```

### 奇偶树
如果一棵二叉树满足下述几个条件，则可以称为 奇偶树 ：

  - 二叉树根节点所在层下标为 0 ，根的子节点所在层下标为 1 ，根的孙节点所在层下标为 2 ，依此类推。  
  - 偶数下标 层上的所有节点的值都是 奇 整数，从左到右按顺序 严格递增
  - 奇数下标 层上的所有节点的值都是 偶 整数，从左到右按顺序 严格递减

给你二叉树的根节点，如果二叉树为 奇偶树 ，则返回 true ，否则返回 false 。  
示例 1：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/04/sample_1_1966.png)
>输入：root = [1,10,4,3,null,7,9,12,8,6,null,null,2]  
输出：true  
解释：每一层的节点值分别是：  
0 层：[1]  
1 层：[10,4]  
2 层：[3,7,9]  
3 层：[12,8,6,2]  
由于 0 层和 2 层上的节点值都是奇数且严格递增，而 1 层和 3 层上的节点值都是偶数且严格递减，因此这是一棵奇偶树。  

示例 2：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/04/sample_2_1966.png)
>输入：root = [5,4,2,3,3,7]  
输出：false  
解释：每一层的节点值分别是：  
0 层：[5]  
1 层：[4,2]  
2 层：[3,3,7]  
2 层上的节点值不满足严格递增的条件，所以这不是一棵奇偶树。  

示例 3：
![](https://assets.leetcode-cn.com/aliyun-lc-upload/uploads/2020/10/04/sample_1_333_1966.png)
>输入：root = [5,9,1,3,5,7]  
输出：false  
解释：1 层上的节点值应为偶数。  

示例 4：  

>输入：root = [1]  
输出：true  

示例 5：  

>输入：root = [11,8,6,1,3,9,11,30,20,18,16,12,10,4,2,17]  
输出：true  


提示：
>树中节点数在范围 [1, 105] 内  
1 <= Node.val <= 106  

#### Code

```cpp
class Solution {
   public:
    bool isEvenOddTree(TreeNode *root) {
        int depth = 0;
        queue<TreeNode *> Q;
        Q.emplace(root);
        while (!Q.empty()) {
            int n = Q.size();
            auto t = Q.front();
            Q.pop();
            if (t->left) Q.emplace(t->left);
            if (t->right) Q.emplace(t->right);
            int pre = t->val;
            int cur = pre;
            if (!check(depth, pre)) return false;
            for (int i = 1; i < n; i++) {
                t = Q.front();
                Q.pop();
                if (t->left) Q.emplace(t->left);
                if (t->right) Q.emplace(t->right);
                cur = t->val;
                if (!check(depth, cur) || !judge(depth, pre, cur)) return false;
                pre = cur;
            }
            ++depth;
        }
        return true;
    }

    bool check(int i, int n) {
        if (i % 2) {
            return n % 2 == 0;
        } else {
            return n % 2;
        }
    }

    bool judge(int i, int pre, int cur) {
        if (i % 2) {
            return cur < pre;
        } else {
            return cur > pre;
        }
    }
};
```

### [416. 分割等和子集](https://leetcode-cn.com/problems/partition-equal-subset-sum/)
给定一个只包含正整数的非空数组。是否可以将这个数组分割成两个子集，使得两个子集的元素和相等。
{{<notice warning>}}
注意:
每个数组中的元素不会超过 100
数组的大小不会超过 200
{{</notice>}}

示例 1:
>输入: [1, 5, 11, 5]  
输出: true

解释: 数组可以分割成 [1, 5, 5] 和 [11].


示例 2:
>输入: [1, 2, 3, 5]  
输出: false

解释: 数组不能分割成两个元素和相等的子集.

#### 思路
求解此问题等价于判断是否可以从这些数中选出若干书使得它们的和所有数之和（前提是偶数）的一半。因此这个问题可以转换成01背包问题.  
转移方程
$$ dp[j]=dp[j] ∣ dp[j−nums[i]] $$

#### Code
```cpp
class Solution {
   public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        if (n < 2) return false;
        auto sum = accumulate(nums.begin(), nums.end(), 0);
        if (sum & 1) return false;
        auto _max = *max_element(nums.begin(), nums.end());
        auto target = sum >> 1;
        if (_max > target) return false;
        vector<bool> dp(target + 1, false);
        dp[0] = true;
        for (int i = 0; i < n; i++) {
            for (int j = target; j >= nums[i]; j--)
                dp[j] = dp[j] || dp[j - nums[i]];
        }
        return dp[target];
    }
};
```
