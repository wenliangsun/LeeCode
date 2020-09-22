#include <bits/stdc++.h>

using namespace std;

/**
 * 题目11:盛最多水的容器
 * 给定 n 个非负整数 a1，a2，...，an，每个数代表坐标中的一个点 (i, ai) 。
 * 在坐标内画 n 条垂直线，垂直线 i 的两个端点分别为 (i, ai) 和 (i, 0)。
 * 找出其中的两条线，使得它们与 x 轴共同构成的容器可以容纳最多的水。
 * 双指针
 */
class LeeCode11 {
   public:
    /**
     * 双指针：
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    int maxArea(vector<int>& height) {
        int n = height.size();
        int l = 0, r = n - 1, res = 0;
        while (l < r) {
            int minH = min(height[l], height[r]);
            res = max(res, minH * (r - l));
            if (height[l] < height[r]) l++;
            else r--;
        }
        return res;
    }
};