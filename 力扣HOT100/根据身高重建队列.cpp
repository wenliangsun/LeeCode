#include <bits/stdc++.h>

using namespace std;

/**
 * 题目406：根据身高重建队列
 */

class Solution {
   public:
    // 先按照身高降序排序，如果身高相同，则按人数升序排序
    static bool cmp(vector<int> a, vector<int> b) {
        if (a[0] == b[0]) return a[1] < b[1];
        return a[0] > b[0];
    }
    /**
     * 思路：https://leetcode-cn.com/problems/queue-reconstruction-by-height/solution/gen-ju-shen-gao-zhong-jian-dui-lie-by-leetcode/
     */
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        sort(people.begin(), people.end(), cmp);  // 排序
        vector<vector<int>> res;
        // 将人按照人数放在对应的索引位置
        for (auto p : people) res.insert(res.begin() + p[1], p);
        // 删除占位的空间
        res.erase(res.begin() + people.size(), res.end());
        return res;
    }
};