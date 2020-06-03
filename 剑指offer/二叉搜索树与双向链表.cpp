#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉搜索树和双向链表的转换
 */

class Node {
   public:
    int val;
    Node* left;
    Node* right;

    Node() {}

    Node(int _val) {
        val = _val;
        left = NULL;
        right = NULL;
    }

    Node(int _val, Node* _left, Node* _right) {
        val = _val;
        left = _left;
        right = _right;
    }
};

class Solution {
   public:
    /**
     * 利用二叉搜索树中序遍历的性质，
     * 对于当前结点，我们先中序遍历转换其左子树，此时得到的结果就是左子树部分转换的双向链表，
     * 记末尾结点为pre，则对于当前结点cur，令cur的左指针指向pre，pre的右指针指向cur，
     * 更新pre为当前结点cur，然后遍历当前结点的右子树。
     * 当pre为null是，此时cur为头结点
     *
     */
    Node* pre = nullptr;   // 记录前一个结点
    Node* head = nullptr;  //头结点
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        // 下面这两行转换成循环双向链表
        head->left = pre;
        pre->right = head;
        return head;
    }

    void dfs(Node* cur) {
        if (!cur) return;
        dfs(cur->left);  //先遍历左子树
        if (pre)         // 如果pre不为空，则连接当前结点
            pre->right = cur;
        else  //否则，当前结点是头结点
            head = cur;
        cur->left = pre;
        pre = cur;        // 更新前一个结点为当前结点
        dfs(cur->right);  // 遍历右子树
    }
};