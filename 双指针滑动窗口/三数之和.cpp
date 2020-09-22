#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目15：三数之和
 * 给定一个包含 n 个整数的数组 nums，判断 nums 中是否存在三个元素 a，b，c
 * ，使得 a + b + c = 0 ？找出所有满足条件且不重复的三元组。
 *
 */
class LeeCode15 {
   public:
    /**
     * 启发于两数之和，双指针法
     * 问题的难点是，如果去除重复出现的情况
     */
    vector<vector<int>> threeSum02(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {  // 考虑边界情况
            return res;
        }
        sort(nums.begin(), nums.end());              // 排序
        for (int i = 0; i < nums.size() - 2; i++) {  // 先固定一个数字
            // 如果当前固定的数字之前固定过，则跳过，说明重复了
            if (i == 0 || (i > 0 && nums[i] != nums[i - 1])) {
                int p1 = i + 1;            // 左指针
                int p2 = nums.size() - 1;  // 右指针
                while (p1 < p2) {
                    if (nums[p1] + nums[p2] < -nums[i]) {
                        p1++;
                    } else if (nums[p1] + nums[p2] == -nums[i]) {
                        // 如果p1所指的这个数字之前出现过，则跳过。p1==i+1保证固定数字后面的第一个位置的数字与固定的数字相同，并且其有效时的情况
                        if (p1 == i + 1 || nums[p1] != nums[p1 - 1]) {
                            vector<int> temp{nums[i], nums[p1], nums[p2]};
                            res.push_back(temp);
                        }
                        p1++;
                        p2--;
                    } else {
                        p2--;
                    }
                }
            }
        }
        return res;
    }
    
    /**
     * 思路：三个for循环
     * 时间复杂度O(n^3)
     * 注意这样结果重复使用的了数字，并且有重复的组合
     */
    vector<vector<int>> threeSum01(vector<int>& nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) {
            return res;
        }
        for (int i = 0; i < nums.size() - 2; i++) {
            for (int j = 1; j < nums.size() - 1; j++) {
                for (int k = 2; k < nums.size(); k++) {
                    if (nums[i] + nums[j] + nums[k] == 0) {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        res.push_back(temp);
                    }
                }
            }
        }
        return res;
    }
};