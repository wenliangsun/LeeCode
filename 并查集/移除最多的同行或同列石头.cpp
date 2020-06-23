#include <bits/stdc++.h>

using namespace std;

/**
 * 题目947：移除最多的同行或同列石头
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    /**
     * 按照行列合并，合并之后每一个连通区域最后会剩一个石头，所以最终答案是总数减去连通区域个数
     */
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                // 按照行和列进行合并
                if (stones[i][0] == stones[j][0] ||
                    stones[i][1] == stones[j][1])
                    p[find(i)] = find(j);
            }
        }
        unordered_set<int> hash;
        // 统计
        for (int i = 0; i < n; i++) hash.insert(find(i));
        return n - hash.size();
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};