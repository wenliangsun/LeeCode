#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目39：组合总和
 */
class LeeCode39 {
   public:
    /**
     * 思路：回溯法+剪枝加速
     * 类似于括号生成那题，使用深度优先搜索，做减法
     */
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        if (candidates.size() == 0) {
            return res;
        }
        vector<int> path;
        // sort(candidates.begin(), candidates.end());
        DFS2(candidates, target, 0, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    /**
     * 需要对数组排序
     */
    void DFS1(vector<int> candidates, int residue, int begin,
              vector<int> path) {
        // 当剩余数为0时，表示当前路径可行
        if (residue == 0) {
            res.push_back(path);
            return;
        }
        //去重复，重复的原因是在较深层的结点值考虑了之前考虑过的元素，
        // 因此我们需要设置“下一轮搜索的起点”即可。 再思考思考！！！！
        for (int i = begin; i < candidates.size(); i++) {
            if (residue - candidates[i] < 0) {
                break;
            }
            path.push_back(candidates[i]);
            DFS1(candidates, residue - candidates[i], 0, path);
            path.pop_back();
        }
    }

    /**
     * 不需要对数组排序
     */
    void DFS2(vector<int> candidates, int residue, int begin,
              vector<int> path) {
        if (residue == 0) {
            res.push_back(path);
            return;
        }
        for (int i = begin; i < candidates.size(); i++) {
            // 注意这儿与需要排序的区别！！！
            if (candidates[i] <= residue) {
                path.push_back(candidates[i]);
                DFS2(candidates, residue - candidates[i], i, path);
                path.pop_back();
            }
        }
    }
};