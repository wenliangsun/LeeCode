#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目90：子集II
 */
class LeeCode90 {
   public:
    /**
     * 思路：回溯法 深度优先 构建树
     * 有重复元素的排列、组合、子集等都需要先将数组进行排序
     * 然后在深度优先的时候设置限制条件进行剪枝
     */
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        sort(nums.begin(), nums.end());
        vector<int> path;
        DFS(nums, 0, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    void DFS(vector<int> nums, int begin, vector<int> path) {
        res.push_back(path);
        for (int i = begin; i < nums.size(); i++) {
            // 注意这儿的限制条件！！！保证第一次使用到！！！
            if (i > begin && nums[i] == nums[i - 1]) {
                continue;
            }
            path.push_back(nums[i]);
            DFS(nums, i + 1, path);
            path.pop_back();
        }
    }
};