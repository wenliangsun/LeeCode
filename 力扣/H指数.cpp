#include <bits/stdc++.h>

using namespace std;

/**
 * 题目274：H指数
 */

class Solution {
   public:
    /**
     * 降序排序
     * 时间复杂度：O(nlogn)
     * 空间复杂度：O(1)
     */
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end());
        reverse(citations.begin(), citations.end());
        int idx = 0;
        while (idx < citations.size() && citations[idx] > idx) idx++;
        return idx;
    }
};