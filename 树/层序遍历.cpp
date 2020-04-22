#include <iostream>
#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 层序遍历
 */
class Solution {
   public:
    /**
     * 递归版本
     */
    vector<vector<int>> levelOrder1(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        DFS(root, 0);
        return res;
    }

    /**
     * 非递归版本
     */
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<TreeNode*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size(); // 记录当前层有多少个结点！！
            vector<int> tmp;
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                tmp.push_back(t->val);
                q.pop();
                if (t->left) q.push(t->left);
                if (t->right) q.push(t->right);
            }
            res.push_back(tmp);
        }
        return res;
    }

   private:
    vector<vector<int>> res;
    void DFS(TreeNode* root, int level) {
        // 此时需要构建下一层
        if (res.size() == level) {
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(root->val);
        if (root->left) {
            DFS(root->left, level + 1);
        }
        if (root->right) {
            DFS(root->right, level + 1);
        }
    }
};