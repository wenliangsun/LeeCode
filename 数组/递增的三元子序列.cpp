#include <bits/stdc++.h>

using namespace std;

/**
 * 题目334:递增的三元子序列
 */

class Solution {
   public:
    /**
     * 双指针 + 贪心
     * 两个指针分别表示两个较小的数，找到一个比这两个数都大的数即返回
     *
     * 当已经找到了长度为 2 的递增序列，这时又来了一个比 small
     * 还小的数字，为什么可以直接替换 small 呢， 这样 small 和 mid
     * 在原数组中并不是按照索引递增的关系呀？
     * 即使我们更新了 small ，这个 small
     * 在 mid 后面，没有严格遵守递增顺序，但它隐含着的真相是， 有一个比 small
     * 大比 mid 小的前·最小值出现在 mid 之前。因此，当后续出现比 mid
     * 大的值的时候， 我们一样可以通过当前 small 和 mid 推断的确存在着长度为 3
     * 的递增序列。 所以，这样的替换并不会干扰我们后续的计算！
     */
    bool increasingTriplet(vector<int>& nums) {
        if (nums.size() < 3) return false;
        int small = INT_MAX, mid = INT_MAX;
        for (auto n : nums) {
            if (n <= small) {
                small = n;
            } else if (n <= mid) {
                mid = n;
            } else if (n > mid) {
                return true;
            }
        }
        return false;
    }
};