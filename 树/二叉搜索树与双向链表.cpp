#include <bits/stdc++.h>

using namespace std;

/**
 * 二叉搜索树与双向链表
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
    Node* pre = nullptr; // 记录前一个结点
    Node* head; // 记录头结点
    Node* treeToDoublyList(Node* root) {
        if (!root) return root;
        dfs(root);
        head->left = pre;
        pre->right = head;
        return head;
    }

    // 中序遍历
    void dfs(Node* cur) {
        if (!cur) return;
        dfs(cur->left); // 先左
        // 操作当前
        if (pre) 
            pre->right = cur;
        else
            head = cur;
        cur->left = pre;
        pre = cur;
        dfs(cur->right); // 再右
    }
};