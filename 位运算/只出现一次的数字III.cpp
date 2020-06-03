#include <bits/stdc++.h>

using namespace std;

/**
 * 给定一个非空整数数组，除了某个元素只出现一次以外，其余每个元素均出现了三次。找出那个只出现了一次的元素。
 */

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        // 高逼格的代码 看不懂。。。。
        // int ones = 0, twos = 0;
        // for (auto n : nums) {
        //     ones = ones ^ n & ~twos;
        //     twos = twos ^ n & ~ones;
        // }
        // cout << ones << endl;

        // 通俗版本
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
    }
    return 0;
}
