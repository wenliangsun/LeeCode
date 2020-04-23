#include <unordered_map>

#include "TreeNode.h"

using namespace std;

/**
 * 题目337：打家窃舍III
 */
class LeeCode337 {
   public:
    int rob(TreeNode* root) {
        if (root == nullptr) {
            return 0;
        }
        if (memo.count(root)) {
            return memo[root];
        }
        // 抢，然后去下下家
        int do_it = root->val +
                    (root->left == nullptr
                         ? 0
                         : rob(root->left->left) + rob(root->left->right)) +
                    (root->right == nullptr
                         ? 0
                         : rob(root->right->left) + rob(root->right->right));
        // 不抢，去下家
        int not_do = rob(root->left) + rob(root->right);
        int res = max(do_it, not_do);
        // 存入备忘录
        memo[root] = res;
        return res;
    }

   private:
    unordered_map<TreeNode*, int> memo;
};