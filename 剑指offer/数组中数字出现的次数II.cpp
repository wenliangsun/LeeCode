#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 因为相同的数字出现了三次，因此不能使用异或操作来做。我们考虑如果一个数字出现3次，那么它的二进制的每一位也会出现3次，
     * 如果把所有出现3次的数字的二进制表示的每一位都分别加起来，那么每一位都能被3整除。
     * 因此，我们将数组中的所有数字的二进制表示的每一位都加起来，如果某一位的和能被3整除，那么说明只出现一次的数字在该位是0，否则是1
     */
    int singleNumber(vector<int>& nums) {
        int m[32] = {0};  // 记录每一位1出现的次数
        for (auto n : nums) {
            // 统计每一位1出现的次数
            for (int i = 0; i < 31; i++) {
                if ((n >> i) & 1) m[i]++;
            }
        }
        int res = 0;
        // 生成只出现一次的数字
        for (int i = 31; i >= 0; i--) {
            res = res << 1;
            res += m[i] % 3;  // 判断当前位是1还是0
        }
        return res;
    }
};
