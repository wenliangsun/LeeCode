#include <bits/stdc++.h>

using namespace std;

/**
 * 题目332：重新安排行程
 */

class Solution {
   public:
    vector<string> res; // 记录答案
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> hash; // 键是起点，值是一个双向队列，里面存的是终点
    /**
     * 欧拉路径问题 转换变形的成后序遍历
     */
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t : tickets) hash[t[0]].push(t[1]);
        string st = "JFK";
        dfs(st); // 深搜 类似后序遍历
        reverse(res.begin(), res.end()); // 将遍历结果翻转就是答案
        return res;
    }

    void dfs(string& s) {
        auto& t = hash[s];
        while (t.size()) { // 先遍历当前结点的孩子
            auto child = t.top();
            t.pop(); // 每遍历一次就删除当前孩子结点的边
            dfs(child);
        }
        res.push_back(s); // 最后访问当前结点
    }
};