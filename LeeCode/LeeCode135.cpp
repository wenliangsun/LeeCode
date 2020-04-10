#include <iostream>
#include <vector>

using namespace std;

/**
 * 题目135：分发糖果
 */
class Solution {
   public:
    /**
     * 思路：贪心思想
     * 先从左向右遍历，遇到比当前评分高的就在当前评分的基础上+1，否则不变
     * 然后从右向左遍历，如果遇到比当前评分高的切其糖果数量小于等于当前评分获得的糖果数量，
     * 则在当前评分的基础上+1 否则不变
     * 时间复杂度：O(n)
     * 空间复杂度：O(n) 
     */
    int candy(vector<int>& ratings) {
        // 初始化糖果数量，每人至少有一颗糖果
        vector<int> temp(ratings.size(), 1);
        // 从左向右遍历
        for (int i = 1; i < ratings.size(); i++) {
            if (ratings[i] > ratings[i - 1]) {
                temp[i] = temp[i - 1] + 1;
            }
        }
        // 从右向左遍历
        for (int i = ratings.size() - 2; i >= 0; i--) {
            if (ratings[i] > ratings[i + 1] && temp[i] <= temp[i + 1]) {
                temp[i] = temp[i + 1] + 1;
            }
        }
        int res = 0;
        // 求糖果的总数
        for (int i = 0; i < temp.size(); i++) {
            res += temp[i];
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<int> nums = {1, 3, 2, 2, 1};
    int res = s.candy(nums);
    cout << res << endl;
}