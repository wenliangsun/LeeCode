#include <bits/stdc++.h>

using namespace std;

/**
 * 题目386：字典序排数
 */

class Solution {
public:
    /**
     * 其实就是N叉树的先序遍历，每个结点有1-9个孩子结点
     */
    vector<int> res;
    vector<int> lexicalOrder(int n) {
        for (int i = 1; i < 10; i++) {
            dfs(n, i);
        }
        return res;
    }

    void dfs(int n, int cur) {
        if (cur > n) return;
        res.push_back(cur);
        for (int i = 1; i < 10; i++) {
            dfs(n, cur * 10 + i);
        }
    }
};