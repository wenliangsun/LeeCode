#include <stack>

#include "TreeNode.h"

using namespace std;

class BSTIterator {
   public:
    // 其实是迭代版本中序遍历的拆分
    stack<TreeNode*> stk;
    BSTIterator(TreeNode* root) {
        while (root) {
            stk.push(root);
            root = root->left;
        }
    }

    /** @return the next smallest number */
    int next() {
        auto t = stk.top();
        stk.pop();
        int res = t->val;
        t = t->right;
        while (t) {
            stk.push(t);
            t = t->left;
        }
        return res;
    }

    /** @return whether we have a next smallest number */
    bool hasNext() { return !stk.empty(); }
};