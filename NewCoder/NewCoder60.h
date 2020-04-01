#include <queue>
#include <vector>
#include "TreeNode.h"

using namespace std;

/**
 * 题目60：把二叉树打印成多行
 * 从上到下按层打印二叉树，同一层结点从左至右输出。每一层输出一行。
 */
class NewCoder60 {
   public:
    /**
     * 思路：利用队列，并设置标志位
     */
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr) {
            return res;
        }
        queue<TreeNode*> q;
        q.push(pRoot);
        q.push(nullptr);
        bool finished = false;  // 标志位
        vector<int> temp;
        while (!q.empty()) {
            if (finished) {
                temp.clear();  // 擦除vector中的所有元素
            }
            TreeNode* node = q.front();
            if (node != nullptr) {  // 如果没有到达标志位，则添进当前路径
                temp.push_back(node->val);
                if (node->left != nullptr) {  // 左子节点入队
                    q.push(node->left);
                }
                if (node->right != nullptr) {  // 左子节点入队
                    q.push(node->right);
                }
                q.pop();  // 队首出队
                finished = false;
            } else {                  // 到达标志位
                res.push_back(temp);  // 将该路径打印的结果保存
                q.pop();              // 移除上一次路径的标志位
                if (!q.empty()) {  // 如果队列不为空，则为当前路径设置标志位
                    q.push(nullptr);
                }
                finished = true;
            }
        }
        return res;
    }
};