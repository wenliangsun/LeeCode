#include <vector>

using namespace std;

/**
 * 题目46：全排列
 */
class LeeCode46 {
   public:
    /**
     * 回溯法, 递归
     * 全排列当前位置可以出现的数字，然后再递归全排列当前位置之后的数字。
     */
    vector<vector<int>> permute(vector<int>& nums) {
        if (nums.size() == 0) {
            return res;
        }
        // permute(nums, 0);
        vector<int> path;
        bool used[nums.size()];  // 用来标记当前排列中元素是否使用了
        for (int i = 0; i < nums.size(); i++) {
            used[i] = false;
        }
        DFS(nums, 0, used, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    // begin 表示当面位置
    void permute(vector<int> nums, int begin) {
        if (begin == nums.size()) {
            res.push_back(nums);
            return;
        }
        // begin 表示当前位置，列举当前位置上可以出现的数字
        for (int i = begin; i < nums.size(); i++) {
            swap(nums, begin, i);  // 交换当前位置数字
            //找下一位置, 回溯法注意这儿begin+1参数，不能更改当前状态下begin的值
            permute(nums, begin + 1);
            swap(nums, begin, i);  // 交换回来
        }
    }
    // 交换两个元素
    void swap(vector<int>& nums, int index1, int index2) {
        int temp = nums[index1];
        nums[index1] = nums[index2];
        nums[index2] = temp;
    }

    /**
     * 回溯法，深度优先，树型结构
     * 需要一个标记数组来记录元素是否被访问过，
     * 因为没有重复的元素，所以不需要对数组进行排序。
     */
    void DFS(vector<int> nums, int begin, bool* used, vector<int> path) {
        if (begin == nums.size()) {
            res.push_back(path);
            return;
        }
        // 注意：这人需要遍历所有的数组元素来获得排列！！！
        for (int i = 0; i < nums.size(); i++) {
            if (!used[i]) {
                path.push_back(nums[i]);
                used[i] = true;
                DFS(nums, begin + 1, used, path);
                path.pop_back();
                used[i] = false;
            }
        }
    }
};