#include <bits/stdc++.h>

using namespace std;

/**
 * 两个数组的交集II
 */

class Solution {
   public:
    /**
     * 如果 nums2
     * 的元素存储在磁盘上，磁盘内存是有限的，并且你不能一次加载所有的元素到内存中，你该怎么办？
     * 只能用这种方法
     * 时间复杂度：O(m+n)
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> hash;
        for (auto n : nums1) hash[n]++;
        vector<int> res;
        for (auto n : nums2) {
            if (hash.count(n) && hash[n] > 0) {
                res.push_back(n);
                hash[n]--;
            }
        }
        return res;
    }

    /**
     * 排序+双指针
     * 时间复杂度：O(mlogm + nlogn)
     */
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        sort(nums1.begin(), nums1.end());
        sort(nums2.begin(), nums2.end());
        int idx1 = 0, idx2 = 0;
        vector<int> res;
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] < nums2[idx2])
                idx1++;
            else if (nums1[idx1] > nums2[idx2])
                idx2++;
            else {
                res.push_back(nums1[idx1]);
                idx1++;
                idx2++;
            }
        }
        return res;
    }
};