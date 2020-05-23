#include <deque>
#include <vector>
#include "TreeNode.h"

using namespace std;

/**
 * 题目59：按之字形顺序打印二叉树
 * 请实现一个函数按照之字形打印二叉树，即第一行按照从左到右的顺序打印，
 * 第二层按照从右至左的顺序打印，第三行按照从左到右的顺序打印，其他行以此类推。
 */
class NewCoder59 {
   public:
    /**
     * 思路：采用双向队列
     * 分两部分：
     * (1) 从左往右打印，即队首到队尾遍历，若未遇到标志位，则队首出队，并将其左右节点依次入队尾。
     * (2) 从右往左打印，即队尾到队首遍历，若未遇到标志位，则队尾出队，并将其右左节点依次入队首。
     */
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (pRoot == nullptr) {
            return res;
        }
        deque<TreeNode*> dq;
        dq.push_back(pRoot);
        dq.push_back(nullptr);  // 标志位：用来分隔从左到右，从右到左的结点数
        bool reverse = false;  // 指示是否翻转即从右往左打印
        while (dq.size() != 1) { // 注意终止条件
            vector<int> temp;
            if (!reverse) {  // 从左往右打印
                while (!dq.empty()) {
                    // 如果未遇到标志位，则添加该结点的值
                    if (dq.front() != nullptr) {  // 操作队首，从队首向队尾
                        TreeNode* node = dq.front();
                        temp.push_back(node->val);
                        if (node->left != nullptr) {  // 将左子结点入队
                            dq.push_back(node->left);
                        }
                        if (node->right != nullptr) {  // 将右子结点入队
                            dq.push_back(node->right);
                        }
                        dq.pop_front();  // 队首元素出队
                    } else {
                        res.push_back(temp);
                        reverse = true;
                        break;
                    }
                }
            } else {
                while (!dq.empty()) {
                    if (dq.back() != nullptr) {  // 操作对位，从队尾向队首
                        TreeNode* node = dq.back();
                        temp.push_back(node->val);
                        if (node->right != nullptr) {  // 注意这儿先如右子结点
                            dq.push_front(node->right);
                        }
                        if (node->left != nullptr) {
                            dq.push_front(node->left);
                        }
                        dq.pop_back();
                    } else {
                        res.push_back(temp);
                        reverse = false;
                        break;
                    }
                }
            }
        }
        return res;
    }
};