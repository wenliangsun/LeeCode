#include <bits/stdc++.h>

using namespace std;

/**
 * 题目611：有效三角形的个数
 */

class Solution {
   public:
    /**
     * 暴力
     * 时间复杂度：O(n^3)
     */
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0;
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = i + 1; j < nums.size() - 1; j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (nums[i] + nums[j] > nums[k] &&
                        nums[i] + nums[k] > nums[j] &&
                        nums[j] + nums[k] > nums[i])
                        res++;
                }
            }
        }
        return res;
    }

    /**
     * 二分法
     * 先对数组进行排序。假设 a < b < c ,所以a + c > b 和 b + c > a，
     * 一定都满足，只需要找满足a + b > c 的最大的c，
     * 然后用c对应的索引减去b对应的索引就固定a，b时的三角形个数
     * 时间复杂度：O(n^2logn)
     */
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size() - 2; i++) {
            int k = i + 2;
            // 这个条件理解一下！！！
            for (int j = i + 1; j < nums.size() - 1 && nums[i] != 0; j++) {
                int l = i + 1, r = nums.size() - 1;
                while (l < r) {
                    int mid = l + r + 1 >> 1;
                    if (nums[mid] < nums[i] + nums[j])
                        l = mid;
                    else
                        r = mid - 1;
                }
                res += l - j;
            }
        }
        return res;
    }

    /**
     * 双指针
     * 固定最长的一条边，运用双指针扫描
     * 如果 nums[l] + nums[r] > nums[i]，同时说明 nums[l + 1] + nums[r] >
     * nums[i], ..., nums[r - 1] + nums[r] > nums[i]， 满足的条件的有 r - l
     * 种，r 左移进入下一轮。如果 nums[l] + nums[r] <= nums[i]，l
     * 右移进入下一轮。 时间复杂度：O(n^2)
     */
    int triangleNumber(vector<int>& nums) {
        if (nums.size() < 3) return 0;
        int res = 0;
        sort(nums.begin(), nums.end());
        for (int i = nums.size() - 1; i >= 2; i--) {
            int l = 0, r = i - 1;
            while (l < r) {
                if (nums[l] + nums[r] > nums[i]) {
                    res += r - l;
                    r--;
                } else
                    l++;
            }
        }
        return res;
    }
};