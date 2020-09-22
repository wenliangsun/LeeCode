#include <bits/stdc++.h>

using namespace std;

/**
 * 题目436：寻找右区间
 */

class Solution {
public:
    /**
     * 排序 + 二分查找
     * 时间复杂度：O(nlogn)
     * 先将区间的左坐标和索引号配对，然后对配对的新数组按照左坐标进行排序，
     * 然后遍历每一个区间，二分查找区间的右坐标所在的位置
     */
    typedef pair<int, int> PII;
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        int n = intervals.size();
        vector<PII> tmp;
        for (int i = 0; i < n; i++) { // 构建数组
            tmp.push_back({intervals[i][0], i});
        }
        sort(tmp.begin(), tmp.end()); // 排序
        vector<int> res;
        for (int i = 0; i < n; i++) {
            res.push_back(binarySearch(tmp, intervals[i][1])); // 二分查找
        }
        return res;
    }

    int binarySearch(vector<PII>& tmp, int num) {
        int n = tmp.size();
        if (tmp[n - 1].first < num) return -1;
        int l = 0, r = n - 1;
        while (l < r) {
            int mid = (l + r) >> 1;
            if (tmp[mid].first >= num) r = mid;
            else l = mid + 1;
        }
        return tmp[l].second;
    }
};