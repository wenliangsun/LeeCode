#include <bits/stdc++.h>

using namespace std;

/**
 * 题目230：二叉搜索树中第K小元素
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
   public:
    /**
     * 非递归版本中序遍历
     */
    int kthSmallest(TreeNode *root, int k) {
        stack<TreeNode *> stk;
        int cnt = 0, res;
        while (root || !stk.empty()) {
            while (root) {
                stk.push(root);
                root = root->left;
            }
            root = stk.top();
            stk.pop();
            res = root->val;
            cnt++;
            if (cnt == k) {
                break;
            }
            root = root->right;
        }
        return res;
    }
};