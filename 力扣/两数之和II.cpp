#include <bits/stdc++.h>

using namespace std;

/**
 * 题目167：两数之和II
 */

class Solution {
   public:
    /**
     * 双指针
     */
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n = numbers.size();
        int l = 0, r = n - 1;
        vector<int> res;
        while (l < r) {
            if (numbers[l] + numbers[r] == target) {
                res.push_back(l + 1), res.push_back(r + 1);
                return res;
            } else if (numbers[l] + numbers[r] < target)
                l++;
            else
                r--;
        }
        return res;
    }
};