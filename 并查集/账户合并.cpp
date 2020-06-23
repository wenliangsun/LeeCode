#include <bits/stdc++.h>

using namespace std;

/**
 * 题目721：账户合并
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        int n = accounts.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化，自己指向自己
        unordered_set<string> hash;  // 用于判断邮箱是否已经出现
        unordered_map<string, int> father;  // 用于记录当前邮箱的父辈
        // 遍历每个人名下的每个邮箱，遍历结束后会得到更新后的父辈关系
        for (int i = 0; i < n; i++) {
            for (int j = 1; j < accounts[i].size(); j++) {
                // 判断该邮箱是否是第一次出现
                if (!hash.count(accounts[i][j])) {  // 若是的话，标记父辈
                    hash.insert(accounts[i][j]);
                    father[accounts[i][j]] = i;
                } else {  // 如不是，则合并当前结点和父辈结点
                    p[find(father[accounts[i][j]])] = find(i);
                }
            }
        }
        // 遍历accounts中每个人名，寻找每个人名的父辈，并将该人名下所有邮箱保存到一起
        unordered_map<int, set<string>> t;
        for (int i = 0; i < n; i++) {
            int f = find(i);  // 寻找当前用户的父辈
            // 将当前人名下的邮箱添加到父辈下
            for (int j = 1; j < accounts[i].size(); j++)
                t[f].insert(accounts[i][j]);
        }

        vector<vector<string>> res;
        // 构造答案数组
        for (auto a : t) {
            vector<string> ans;
            ans.push_back(accounts[a.first][0]);
            for (auto m : a.second) ans.push_back(m);
            res.push_back(ans);
        }
        return res;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};