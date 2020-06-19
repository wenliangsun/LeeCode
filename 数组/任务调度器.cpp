#include <bits/stdc++.h>

using namespace std;

/**
 * 题目621：任务调度器
 */

class Solution {
   public:
    /**
     * 思路：首先安排数量最多的任务，假设数量为k，则k-1组中需要 (k-1) * (n+1)
     * 的时间， 然后将剩余的任务加上去，即和A有相同数量的任务都加1，
     * 最后考虑特殊情况，不需要等待，就可以完成，即需要时间为所有任务的数量。
     * https://leetcode-cn.com/problems/task-scheduler/solution/wan-zheng-de-qing-xi-de-jie-shi-yong-yi-ge-li-zi-s/
     */
    int leastInterval(vector<char>& tasks, int n) {
        int nt = tasks.size();
        int m[26] = {0};
        for (auto t : tasks) m[t - 'A']++;  // 统计每个任务的数量
        int mx = *max_element(m, m + 26);   // 找出最大数量
        int res = (mx - 1) * (n + 1);       // 计算最大数量-1组的时间
        for (int i = 0; i < 26; i++) {      // 加上最后一组的时间
            if (m[i] == mx) res++;
        }
        return max(nt, res);  // 考虑不需要等待的情况
    }
};