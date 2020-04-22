#include <stack>

#include "TreeNode.h"

using namespace std;

class Solution {
   public:
    // 递归写法
    bool isSymmetric(TreeNode* root) { return dfs(root, root); }

    bool isSymmetric2(TreeNode* root) {
        if (!root) return true;
        stack<TreeNode*> left, right;
        auto l = root->left, r = root->right;
        while (l || r || left.size() || right.size()) {
            while (l && r) {
                left.push(l), l = l->left;
                right.push(r), r = r->right;
            }
            if (l || r) return false;
            l = left.top(), left.pop();
            r = right.top(), right.pop();
            if (l->val != r->val) return false;
            l = l->right, r = r->left;
        }
        return true;
    }

   private:
    bool dfs(TreeNode* l, TreeNode* r) {
        if (!l && !r) return true;
        if (!l || !r) return false;
        if (l->val != r->val) return false;
        return dfs(l->left, r->right) && dfs(l->right, r->left);
    }
};