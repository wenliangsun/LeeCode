#include <vector>

using namespace std;

/**
 * 题目78：子集
 */
class LeeCode78 {
   public:
    /**
     * 思路：回溯法
     * 每走一步就将该路径添加到结果数组中即可生成数组的子集
     */
    vector<vector<int>> subsets(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        vector<int> path;
        DFS(nums, 0, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    void DFS(vector<int> nums, int begin, vector<int> path) {
        // 每走一步就将该路径添加进结果数组
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++) {
            path.push_back(nums[i]);
            DFS(nums, i + 1, path);
            path.pop_back();
        }
    }
};