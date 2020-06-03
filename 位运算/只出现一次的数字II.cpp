#include <bits/stdc++.h>

using namespace std;

/**
 * 一个整型数组nums里除两个数字之外，其他数字都出现了两次。请写程序找出这两个只出现一次的数字。要求时间复杂度是O(n)，空间复杂度是O(1)。
 */

int main() {
    int n;
    while (cin >> n) {
        vector<int> nums(n);
        for (int i = 0; i < n; i++) cin >> nums[i];
        int n1 = 0, n2 = 0;
        int t = 0;
        for (auto n : nums) t ^= n;  // 异或得到一个不为零的数字
        int idx = 0;
        while (!(t & 1)) {  // 寻找划分标志位
            t >>= 1;
            idx++;
        }
        // 对每一部分分别进行异或
        for (auto n : nums) {
            if ((n >> idx) & 1)
                n1 ^= n;
            else
                n2 ^= n;
        }
        cout << n1 << ' ' << n2 << endl;
    }
    return 0;
}