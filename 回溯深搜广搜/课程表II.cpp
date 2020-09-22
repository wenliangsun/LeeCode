#include <bits/stdc++.h>

using namespace std;

/**
 * 题目210：课程表II
 */

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);
        vector<vector<int>> adj(numCourses);
        for (auto c : prerequisites) {
            indegree[c[0]]++;
            adj[c[1]].push_back(c[0]);
        }
        queue<int> q;
        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) q.push(i);
        }
        vector<int> res;
        while (q.size()) {
            auto t = q.front();
            q.pop();
            res.push_back(t);
            numCourses--;
            for (auto c : adj[t]) {
                if (--indegree[c] == 0) q.push(c);
            }
        }
        if (numCourses == 0) return res;
        else return {};
    }
};