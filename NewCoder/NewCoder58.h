#include <queue>
#include <stack>
#include "TreeNode.h"

using namespace std;

/**
 * 题目58：对称的二叉树
 * 请实现一个函数，用来判断一颗二叉树是不是对称的。
 * 注意，如果一个二叉树同此二叉树的镜像是同样的，定义其为对称的。
 */
class NewCoder58 {
   public:
    bool isSymmetrical(TreeNode* pRoot) { return isSymmetrical(pRoot, pRoot); }

    /**
     * 递归版本
     * 思路：同时从二叉树的左子树和右子树开始遍历，每次遍历的时候判断这两个结点是否相等。
     */
    bool isSymmetrical(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (pRoot1 == nullptr &&
            pRoot2 == nullptr) {  //遍历完，说明对称，返回true
            return true;
        }
        // 如果其中一侧遍历完而另一侧还没，则返回false
        if ((pRoot1 != nullptr && pRoot2 == nullptr) ||
            (pRoot1 == nullptr && pRoot2 != nullptr)) {
            return false;
        }
        if (pRoot1->val != pRoot2->val) {  // 判断两个结点的值是否相等
            return false;
        }
        return isSymmetrical(pRoot1->left, pRoot2->right) &&
               isSymmetrical(pRoot1->right, pRoot2->left);
    }

    /**
     * 深度优先 使用栈数据结构
     * 同时向栈中存入左子节点和右子节点
     */
    bool isSymmetricalDFS(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        stack<TreeNode*> s;
        s.push(pRoot->left);
        s.push(pRoot->right);
        while (!s.empty()) {
            TreeNode* right = s.top();
            s.pop();
            TreeNode* left = s.top();
            s.pop();
            if (right == nullptr && left == nullptr) {
                continue;
            }
            if (right == nullptr || left == nullptr) {
                return false;
            }
            if (right->val != left->val) {
                return false;
            }
            s.push(left->left);
            s.push(right->right);
            s.push(right->left);
            s.push(left->right);
        }
        return true;
    }

    /**
     * 广度优先遍历，使用队列数据结构
     *
     */
    bool isSymmetricalBFS(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return true;
        }
        queue<TreeNode*> q;
        q.push(pRoot->left);
        q.push(pRoot->right);
        while (!q.empty()) {
            TreeNode* left = q.front();
            q.pop();
            TreeNode* right = q.front();
            q.pop();
            if (right == nullptr && left == nullptr) {
                continue;
            }
            if (right == nullptr || left == nullptr) {
                return false;
            }
            if (right->val != left->val) {
                return false;
            }
            q.push(left->left);
            q.push(right->right);
            q.push(right->left);
            q.push(left->right);
        }
        return true;
    }
};