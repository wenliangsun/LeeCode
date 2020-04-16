#include <vector>

using namespace std;

/**
 * 给定一个包含 n + 1 个整数的数组 nums，其数字都在 1 到 n 之间（包括 1 和 n），
 * 可知至少存在一个重复的整数。假设只有一个重复的整数，找出这个重复的数。
 *
 * 思路：抽屉原理 check(性质)：
 * 统计满足每个区间的数字个数，如果个数大于区间长度，则说明里面有重复的数字
 */

class Solution {
   public:
    int findDuplicate(vector<int>& nums) {
        int l = 1, r = nums.size() - 1;
        while (l < r) {
            int mid = l + r >> 1;
            int cnt = 0;
            for (int x : nums) cnt += l <= x && x <= mid;
            if (cnt > mid - l + 1)
                r = mid;
            else
                l = mid + 1;
        }
        return l;
    }
};