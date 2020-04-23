#include <iostream>
#include <map>
#include <vector>

using namespace std;

/**
 * 题目1：两数之和
 * 给定一个整数数组 nums 和一个目标值 target，
 * 请你在该数组中找出和为目标值的那 两个 整数，并返回他们的数组下标。
 */
class LeeCode01 {
   public:
    /**
     * 思路：暴力法，时间复杂度O(n^2)
     */
    vector<int> twoSum01(vector<int>& nums, int target) {
        vector<int> res;
        int i, j;
        for (i = 0; i < nums.size(); i++) {
            for (j = i + 1; j < nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                }
            }
        }
        return res;
    }

    /**
     * 思路：采用哈希表，遍历两次数组
     * 以空间换取时间
     */
    vector<int> twoSum02(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]] = i;
        }

        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end() &&
                m[target - nums[i]] != i) {
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            }
        }
        return res;
    }
    /**
     * 思路：哈希表，遍历一次数组
     */
    vector<int> twoSum03(vector<int>& nums, int target) {
        vector<int> res;
        map<int, int> m;
        for (int i = 0; i < nums.size(); i++) {
            if (m.find(target - nums[i]) != m.end()) {
                res.push_back(i);
                res.push_back(m[target - nums[i]]);
                return res;
            }
            m[nums[i]] = i;
        }
        return res;
    }
};