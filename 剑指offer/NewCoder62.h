#include <vector>
#include "TreeNode.h"

using namespace std;

/**
 * 题目62：二叉搜索树的第k个结点
 * 给定一棵二叉搜索树，请找出其中的第k小的结点。
 * 例如， （5，3，7，2，4，6，8）中，按结点数值大小顺序第三小结点的值为4。
 */
class NewCoder62 {
   public:
    /**
     * 思路：对二叉搜索树进行中序遍历可以得到一个递增的序列，
     * 找到这个序列的第K个结点就是要找的值
     */
    TreeNode* KthNode(TreeNode* pRoot, int k) {
        if (k <= 0) {
            return nullptr;
        }
        midTree(pRoot);
        if (res.size() < k) {
            return nullptr;
        } else {
            return res[k - 1];
        }
    }

   private:
    vector<TreeNode*> res;
    /**
     *  递归中序遍历二叉搜索树
     */
    void midTree(TreeNode* pRoot) {
        if (pRoot == nullptr) {
            return;
        }
        midTree(pRoot->left);
        res.push_back(pRoot);
        midTree(pRoot->right);
    }
};