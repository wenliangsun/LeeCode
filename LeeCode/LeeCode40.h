#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目40：组合总和II
 */
class LeeCode40 {
   public:
    /**
     * 思路：回溯法
     * 采用深度优先算法，做减法
     */
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        vector<int> path;
        sort(candidates.begin(), candidates.end());
        DFS2(candidates, target, 0, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    // 不用对数组排序，会有重复的组合
    void DFS1(vector<int> candidates, int residue, int begin,
              vector<int> path) {
        if (residue == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            if (candidates[i] <= residue) {
                path.push_back(candidates[i]);
                // 注意这儿不能重复使用数组元素，因此从下一个索引开始
                DFS1(candidates, residue - candidates[i], i + 1, path);
                path.pop_back();
            }
        }
    }

    /**
     * 需要对数组进行排序
     */
    void DFS2(vector<int> candidates, int residue, int begin,
              vector<int> path) {
        if (residue == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            // 候选数字大于剩余的数，直接剪枝，大剪枝
            if (residue - candidates[i] < 0) {
                break;
            }
            // 如果当前候选数字已经出现过,则跳过，小剪枝
            if (i > begin && candidates[i] == candidates[i - 1]) {
                continue;
            }
            path.push_back(candidates[i]);
            DFS2(candidates, residue - candidates[i], i + 1, path);
            path.pop_back();
        }
    }
};