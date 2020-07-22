#include <bits/stdc++.h>

using namespace std;

/**
 * 任务调度器
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
        for (auto t : tasks) m[t - 'A']++;
        int mx = 0;
        for (int i = 0; i < 26; i++) mx = max(mx, m[i]);
        int res = (mx - 1) * (n + 1);
        for (int i = 0; i < 26; i++) {
            if (mx == m[i]) res++;
        }
        return max(nt, res);
    }
};