#include <bits/stdc++.h>

using namespace std;

/**
 * 题目210：课程表II
 */

class Solution {
   public:
    /**
     * 广度优先搜索
     * 1.统计课程安排图中每个结点的入度，生成入度表
     * 2.借助一个队列，将所有入度为0的结点入队
     * 3.当队列非空的时候，依次将队首节点出队，在课程安排表中删除此结点
     * (不是真正删除此节点，而是将此节点对应的所有邻接结点的入度减一，如果减一后邻接结点的入度为0，
     * 说明该节点的课程可以学习，则将该节点入队)。
     * 4.每次队列出队时，即当前课程已修完，课程总数减一，最后通过剩余课程是否是0来判断是否可以修完课程
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);     // 统计没门课程的入度
        vector<vector<int>> adj(numCourses);  // 邻接表
        queue<int> q;                         // 队列 用于广度优先搜索
        for (auto c : prerequisites) {  // 统计每个结点的入度，并构建邻接表
            indegree[c[0]]++;
            adj[c[1]].push_back(c[0]);
        }
        for (int i = 0; i < numCourses; i++)  // 将入度为0的结点入队进行遍历
            if (indegree[i] == 0) q.push(i);
        vector<int> res;  // 记录答案
        while (q.size()) {
            int pre = q.front();  // 休当前课程
            q.pop();
            res.push_back(pre);
            numCourses--;            // 课程数量减一
            for (auto c : adj[pre])  // 更新与当前课程相连的结点的入度
                if (--indegree[c] == 0) q.push(c);  // 如果入度为0说明可以修了
        }
        if (numCourses == 0) return res;
        return {};
    }

    vector<int> res;
    /**
      * 深度优先 判断有向图中是否有环
     * 1.借助一个标志列表flag，用于判断每个结点(课程)的状态：
     * (1)未被访问 i=0;
     * (2)已被其他节点启动的dfs访问 i=-1;
     * (3)已被当前结点启动的dfs访问 i=1;
     * 2.对课程的每个结点依次执行dfs，判断每个结点起步的dfs是否有环，若有环直接返回false
     * (1)终止条件：flag[i]=-1,说明当前结点已被其他结点启动的dfs访问，无需重复搜索，直接返回true。flag[i]=1说明在本轮dfs搜索中i被第2次搜索，说明有环，直接返回false。
     * (2)将当前访问的结点的标记置为1，即标记其被本轮dfs访问。
     * (3)递归访问当前节点i的所有邻接节点j，当发现环直接返回 False
     * (4)当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点flag置为−1并返回True。
     */
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> flag(numCourses);
        for (auto c : prerequisites) adj[c[1]].push_back(c[0]); //构建邻接表
        for (int i = 0; i < numCourses; i++) // 从每个课程结点开始遍历
            if (dfs(i, adj, flag)) return {};
        reverse(res.begin(), res.end()); // 翻转一下
        return res;
    }

    bool dfs(int i, vector<vector<int>>& adj, vector<int>& flag) {
        if (flag[i] == 1) return true;  // 说明有环
        if (flag[i] == -1) return false;
        flag[i] = 1;
        for (auto c : adj[i])
            if (dfs(c, adj, flag)) return true;
        res.push_back(i); // 先存入进去的是最后遍历的，所以最后需要翻转一下
        flag[i] = -1;
        return false;
    }
};