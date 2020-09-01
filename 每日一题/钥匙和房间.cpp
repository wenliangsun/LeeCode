#include <bits/stdc++.h>

using namespace std;

/**
 * 题目841：钥匙和房间
 */

class Solution {
public:
    /**
     * 深搜
     * 时间复杂度：O(n + m)
     * 空间复杂度：O(n)
     */
    vector<bool> st;
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        st = vector<bool>(n);
        dfs(rooms, 0);
        for(auto s : st) // 判断所有房间是否被访问过
            if (!s) return false;
        return true;
    }

    void dfs(vector<vector<int>>& rooms, int idx) {
        st[idx] = true;
        for (auto t : rooms[idx]) {
            if (!st[t]) {
                dfs(rooms, t);
            }
        }
    }

    /**
     * 广度优先搜索
     * 时间复杂度：O(n + m)
     * 空间复杂度：O(n)
     */
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        queue<int> q;
        vector<bool> st(n);
        q.push(0);
        st[0] = true;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            for (auto c : rooms[t]) {
                if (!st[c]) {
                    st[c] = true;
                    q.push(c);
                }
            }
        }
        for (auto t : st) {
            if (!t) return false;
        }
        return true;
    }
};