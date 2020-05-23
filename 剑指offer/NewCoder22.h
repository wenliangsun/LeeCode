//
// Created by wenliangsun on 2020/2/10.
//

#ifndef C__ALGORITHM_NEWCODER22_H
#define C__ALGORITHM_NEWCODER22_H

#include "TreeNode.h"
#include <vector>
#include <queue>

#endif //C__ALGORITHM_NEWCODER22_H
using std::vector;
using std::queue;

/**
 * 题目22：从上往下打印二叉树
 * 从上往下打印出二叉树的每个结点，通层结点从左向右打印
 */
class NewCoder22 {
public:
    /**
     * 思路，二叉树的非递归遍历，借助队列！！！
     * @param root
     * @return
     */
    vector<int> PrintFromTopToBottom(TreeNode *root) {
        vector<int> res;
        queue<TreeNode *> q;
        if (root == NULL)
            return res;
        q.push(root); // 入栈根节点
        while (!q.empty()) { // 如果队列不为空，就打印
            TreeNode *temp = q.front(); // 队首元素
            res.push_back(temp->val); // 打印
            q.pop(); // 出队
            if (temp->left != NULL) // 左子树入队
                q.push(temp->left);
            if (temp->right != NULL) // 右子树入队
                q.push(temp->right);
        }
        return res;

    }
};