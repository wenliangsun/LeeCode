#include <queue>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目102：二叉树的层次遍历
 */
class LeeCode102 {
   public:
    /**
     * 思路：bfs 设置标志位 可以优化
     */
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        q.push(nullptr);
        bool finished = false;
        vector<int> temp;
        while (!q.empty()) {
            if (finished) {
                temp.clear();
            }
            TreeNode* node = q.front();
            if (node != nullptr) {
                temp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
                q.pop();
                finished = false;
            } else {
                res.push_back(temp);
                q.pop();
                if (!q.empty()) {
                    q.push(nullptr);
                }
                finished = true;
            }
        }
        return res;
    }

    /**
     * 思路：BFS的优化版 不需要设置标志位
     */
    vector<vector<int>> levelOrder2(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(root);
        while (!q.empty()) {  // 相当于控制层
            vector<int> temp;
            int len = q.size();  // 注意这儿是计算了当前层的长度
            for (int i = 0; i < len; i++) {  // 遍历一层
                TreeNode* node = q.front();
                q.pop();
                temp.push_back(node->val);
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }

    /**
     * 思路：递归法
     */
    vector<vector<int>> levelOrder3(TreeNode* root) {
        if (root == nullptr) {
            return res;
        }
        helper(root, 0);
        return res;
    }

   private:
    vector<vector<int>> res;
    /**
     * 思路：采用先序遍历
     * level 是树的层数
     */
    void helper(TreeNode* root, int level) {
        // 如果结果中的层数等于level，开始新的一层
        if (res.size() == level) {
            vector<int> temp;
            res.push_back(temp);
        }
        res[level].push_back(root->val);
        if (root->left != nullptr) {
            helper(root->left, level + 1);
        }
        if (root->right != nullptr) {
            helper(root->right, level + 1);
        }
    }
};