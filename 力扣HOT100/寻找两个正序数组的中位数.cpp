#include <bits/stdc++.h>

using namespace std;

/**
 * 寻找两个正序数组的中位数
 */

class Solution {
   public:
    /**
     * 归并到一个数组中，找中位数
     * 时间复杂度：O(m + n)
     * 空间复杂度：O(m + n) 
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size(), n = nums2.size();
        vector<int> tmp;
        int i = 0, j = 0;
        while (i < m && j < n) {
            if (nums1[i] < nums2[j])
                tmp.push_back(nums1[i++]);
            else
                tmp.push_back(nums2[j++]);
        }
        while (i < m) tmp.push_back(nums1[i++]);
        while (j < n) tmp.push_back(nums2[j++]);
        if (tmp.size() & 1)
            return tmp[tmp.size() / 2];
        else
            return ((double)tmp[tmp.size() / 2 - 1] + tmp[tmp.size() / 2]) / 2;
    }
};