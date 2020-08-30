#include <bits/stdc++.h>

using namespace std;

/**
 * 题目477：汉明距离总和
 */

class Solution {
public:
    /**
     * 位运算：每次遍历数组的一位上有多少0和多少1，该位的汉明距离的和就是0的个数×1的个数，
     * 因为0和0，1和1的汉明距离都是0。然后遍历32位，全部加起来即可。
     * 时间复杂度：O(n*32)
     * 空间复杂度：O(1)
     */
    int totalHammingDistance(vector<int>& nums) {
        int res = 0;
        for (int i = 0; i < 32; i++) {
            int nzero = 0, none = 0;
            for (auto n : nums) {
                if ((n >> i) & 1) none++;
                else nzero++;
            }
            res += nzero * none;
        }
        return res;
    }
};