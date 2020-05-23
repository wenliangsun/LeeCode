#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目47:全排列II
 */
class LeeCode47 {
   public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        bool used[nums.size()];
        for (int i = 0; i < nums.size(); i++) {
            used[i] = false;
        }
        vector<int> path;
        sort(nums.begin(), nums.end());
        DFS(nums, 0, used, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    // 需要排序！！！
    void DFS(vector<int> nums, int begin, bool* used, vector<int> path) {
        if (begin == nums.size()) {
            res.push_back(path);
            return;
        }
        for (int i = 0; i < nums.size(); i++) {
            // 注意这儿used[i-1]前面加不加!都可以，再理解一下！！！
            if (used[i] || (i > 0 && nums[i] == nums[i - 1] && used[i - 1])) {
                continue;
            }
            path.push_back(nums[i]);
            used[i] = true;
            DFS(nums, begin + 1, used, path);
            path.pop_back();
            used[i] = false;
        }
    }
};