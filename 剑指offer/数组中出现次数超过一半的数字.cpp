#include <bits/stdc++.h>

using namespace std;

class Solution {
   public:
    /**
     * 投票法
     */
    int majorityElement(vector<int>& nums) {
        int cnt = 0, val = -1;
        for (auto n : nums) {
            if (!cnt)
                val = n, cnt = 1;
            else {
                if (n == val)
                    cnt++;
                else
                    cnt--;
            }
        }
        return val;
    }

    /**
     * 哈希表
     */
    int majorityElement(vector<int>& nums) {
        unordered_map<int, int> hash;
        for (auto n : nums) hash[n]++;
        int res = 0;
        for (auto item : hash) {
            if (item.second > nums.size() / 2) {
                res = item.first;
            }
        }
        return res;
    }

    /**
     * 排序
     */
    int majorityElement(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        return nums[nums.size() / 2];
    }
};