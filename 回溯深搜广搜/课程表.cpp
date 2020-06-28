#include <bits/stdc++.h>

using namespace std;

/**
 * 题目207：课程表
 */

class Solution {
   public:
    /**
     * 本题可约化为：课程安排图是否是有向无环图(DAG)。即课程间规定了前置条件，但不能构成任何环路，否则课程前置条件将不成立。
     *
     * 广度优先搜索， 拓扑排序
     * 1.统计课程安排图中每个结点的入度，生成入度表
     * 2.借助一个队列，将所有入度为0的结点入队
     * 3.当队列非空的时候，依次将队首节点出队，在课程安排表中删除此结点
     * (不是真正删除此节点，而是将此节点对应的所有邻接结点的入度减一，如果减一后邻接结点的入度为0，
     * 说明该节点的课程可以学习，则将该节点入队)。
     * 4.每次队列出队时，即当前课程已修完，课程总数减一，最后通过剩余课程是否是0来判断是否可以修完课程
     *
     */
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses);     // 统计每门课程的入度
        vector<vector<int>> adj(numCourses);  // 邻接表
        queue<int> q;                         // 队列
        // 统计入度以及构建邻接表
        for (auto c : prerequisites) {
            indegree[c[0]]++;
            adj[c[1]].push_back(c[0]);
        }
        // 将入度为0的课程结点入队
        for (int i = 0; i < numCourses; i++)
            if (indegree[i] == 0) q.push(i);
        while (q.size()) {
            int pre = q.front();  // 当前课程出队
            q.pop();
            numCourses--;  // 剩余课程减一
            // 与当前结点相邻的结点的入度减一
            for (auto c : adj[pre])
                // 如果相邻结点的入度减一之后等于0，说明该节点的课程可以修，该节点入队
                if (--indegree[c] == 0) q.push(c);
        }
        // 最后判断能否修完所有课程
        return numCourses == 0;
    }

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
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> flag(numCourses);
        for (auto c : prerequisites) adj[c[1]].push_back(c[0]);  //构建邻接表
        for (int i = 0; i < numCourses; i++) {  // 从每个课程结点开始遍历
            if (!dfs(adj, flag, i)) return false;
        }
        return true;
    }

    bool dfs(vector<vector<int>>& adj, vector<int>& flag, int i) {
        if (flag[i] == 1) return false;
        if (flag[i] == -1) return true;
        flag[i] = 1; // 将当前访问的结点的标记置为1，即标记其被本轮dfs访问
        // 递归遍历当前结点的邻接结点
        for (auto c : adj[i]) {
            if (!dfs(adj, flag, c)) return false;
        }
        flag[i] = -1; // 当前节点所有邻接节点已被遍历，并没有发现环，则将当前节点flag置为−1
        return true;
    }
};