#include <bits/stdc++.h>

using namespace std;

/**
 * 力扣60：第k个排列
 */

class Solution {
public:
    string getPermutation(int n, int k) {
        int jie[10];
        jie[0] = 1;
        string nums;
        for (int i = 1; i <= n; i++) {
            jie[i] = jie[i - 1] * i;
            nums += to_string(i);
        }
        k--; // k的索引是从1开始的，需要减一
        string res;
        while (nums.size()) {
            int len = nums.size();
            int idx = k / jie[len - 1];
            k %= jie[len - 1];
            res += nums[idx];
            nums.erase(nums.begin() + idx);
        }
        return res;
    }
};