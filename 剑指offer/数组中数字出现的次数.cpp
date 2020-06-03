#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 只有一个只出现一次的数字，其他数字都出现了两次，则可通过异或求得该数字
     * 而有两个只出现一次的数字，我们可以考虑将数组分成两部分，每一部分中都只有一个数字出现了一次，其余数字都出现了两次
     * 然后分别用异或求数字
     * 1.对所有数字进行异或，可以得到一个数字，该数字一定不为0，说明其中必定有一位是1，然后以这一位是否为1作为划分规则，划分数据（出现两次的数字一定会出现在同一组里，因为相同的数字他们的位是一样的）
     * 2.然后对两部分数据分别进行异或运算即可求得数字
     */
    vector<int> singleNumbers(vector<int>& nums) {
        int n1 = 0, n2 = 0;
        int t = 0;
        for (auto n : nums) t ^= n;
        int idx = 0;
        while (!(t & 1)) {
            t >>= 1;
            idx++;
        }
        for (auto n : nums) {
            if ((n >> idx) & 1)
                n1 ^= n;
            else
                n2 ^= n;
        }
        return {n1, n2};
    }
};