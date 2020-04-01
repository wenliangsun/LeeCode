#include <deque>
#include <vector>

#include "TreeNode.h"

using namespace std;

/**
 * 题目103:二叉树的锯齿形层次遍历
 */
class LeeCode103 {
   public:
    /**
     * 思路：利用双向队列 并设置标志位
     */
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (root == nullptr) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(root);
        dq.push_back(nullptr);
        bool reversed = false;
        while (dq.size() != 1) {
            vector<int> temp;
            if (!reversed) {
                while (!dq.empty()) {
                    if (dq.front() != nullptr) {
                        TreeNode* node = dq.front();
                        temp.push_back(node->val);
                        if (node->left != nullptr) {
                            dq.push_back(node->left);
                        }
                        if (node->right) {
                            dq.push_back(node->right);
                        }
                        dq.pop_front();
                    } else {
                        res.push_back(temp);
                        reversed = true;
                        break;
                    }
                }
            } else {
                while (!dq.empty()) {
                    if (dq.back() != nullptr) {
                        TreeNode* node = dq.back();
                        temp.push_back(node->val);
                        if (node->right != nullptr) {
                            dq.push_front(node->right);
                        }
                        if (node->left != nullptr) {
                            dq.push_front(node->left);
                        }
                        dq.pop_back();
                    } else {
                        res.push_back(temp);
                        reversed = false;
                        break;
                    }
                }
            }
        }
        return res;
    }
};