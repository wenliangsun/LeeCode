#include <vector>

using namespace std;

/**
 * 题目4:寻找两个有序数组的中位数
 * 给定两个大小为 m 和 n 的有序数组 nums1 和 nums2。
 * 请你找出这两个有序数组的中位数，并且要求算法的时间复杂度为 O(log(m + n))。
 * 你可以假设 nums1 和 nums2 不会同时为空。
 */
class LeeCode04 {
   public:
    /**
     * 思路：先合并两个排序的数组，然后求中位数
     */
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int p1 = 0;
        int p2 = 0;
        vector<int> temp;
        while (p1 < nums1.size() && p2 < nums2.size()) {
            if (nums1[p1] < nums2[p2]) {
                temp.push_back(nums1[p1]);
                p1++;
            } else {
                temp.push_back(nums2[p2]);
                p2++;
            }
        }
        while (p1 < nums1.size()) {
            temp.push_back(nums1[p1++]);
        }
        while (p2 < nums2.size()) {
            temp.push_back(nums2[p2++]);
        }
        int len = temp.size();
        if (len % 2 == 0) {
            return (temp[len / 2 - 1] + temp[len / 2]) / 2.;
        } else {
            return temp[len / 2];
        }
    }
};