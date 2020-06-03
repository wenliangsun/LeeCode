#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 重新定义排序规则
     */
    static bool cmp(int a, int b) {
        string s1 = to_string(a) + to_string(b);
        string s2 = to_string(b) + to_string(a);
        return s1 < s2;
    }

    string minNumber(vector<int>& nums) {
        sort(nums.begin(), nums.end(), cmp);  // 排序
        string res;
        for (auto n : nums) res += to_string(n);
        return res;
    }
};