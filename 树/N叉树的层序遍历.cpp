#include <bits/stdc++.h>

using namespace std;

/**
 * 题目429：N叉树的层序遍历
 */

class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};


class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> res;
        if (!root) return res;
        queue<Node*> q;
        q.push(root);
        while (q.size()) {
            int len = q.size();
            vector<int> tmp;
            for (int i = 0; i < len; i++) {
                auto t = q.front();
                q.pop();
                tmp.push_back(t->val);
                for (auto n : t->children) q.push(n);
            }
            res.push_back(tmp);
        }
        return res;
    }
};