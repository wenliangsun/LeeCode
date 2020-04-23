#include <vector>

using namespace std;

/**
 * 题目77：组合
 */
class LeeCode77 {
   public:
    /**
     * 思路：回溯法
     * 和全排列思路类似，只是在构造树的时候不一样
     */
    vector<vector<int>> combine(int n, int k) {
        if (k <= 0 || n <= 0) {
            return res;
        }
        vector<int> path;
        DFS(n, 1, k, path);
        return res;
    }

   private:
    vector<vector<int>> res;
    void DFS(int n, int begin, int k, vector<int> path) {
        if (k == path.size()) {
            res.push_back(path);
            return;
        }
        // 这儿构建树的时候前面用过就不再使用
        for (int i = begin; i <= n; i++) {
            path.push_back(i);
            DFS(n, i + 1, k, path);
            path.pop_back();
        }
    }
};