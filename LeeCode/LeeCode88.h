#include <vector>

using namespace std;

/**
 * 题目88：合并两个有序数组
 */
class LeeCode88 {
   public:
    /**
     * 思路：双指针，从后往前
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        int index = m + n - 1;
        while (n > 0) {
            if (m == 0 || nums2[n - 1] > nums1[m - 1]) {
                nums1[index] = nums2[n - 1];
                n--;
                index--;
            } else {
                nums1[index] = nums1[m - 1];
                m--;
                index--;
            }
        }
    }
};