#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目57：插入区间
 */
class LeeCode57 {
   public:
    /**
     * 思路：由于数组是按区间排序的，所以我们可以利用合并区间的思路，
     * 只是考虑插入区间在数组中的位置以及此时的情况。
     * 空间复杂度还可以进一步优化！！！
     * 时间复杂度：O(n)
     * 空间复杂度：O(n)
     */
    vector<vector<int>> insert(vector<vector<int>>& intervals,
                               vector<int>& newInterval) {
        vector<vector<int>> res;
        // 排除特征情况
        if (intervals.size() == 0 && newInterval.size() == 0) {
            return res;
        } else if (intervals.size() == 0) {
            res.push_back(newInterval);
            return res;
        }

        // 考虑插入区间可能在数组中的第一个位置
        if (newInterval[0] < intervals[0][0]) {
            res.push_back(newInterval);
        } else {
            res.push_back(intervals[0]);
        }
        // 考虑插入区间在数组中的最后一个位置，直接将其添加到数组中
        if (intervals[intervals.size() - 1][0] < newInterval[0]) {
            intervals.push_back(newInterval);
        }
        int index = 0;
        for (int i = 0; i < intervals.size(); i++) {
            // 如果当前位置不是插入区间的位置，按合并区间的方法合并区间
            if (newInterval[0] > intervals[i][0]) {
                if (res[index][1] >= intervals[i][0]) {
                    res[index][1] = max(res[index][1], intervals[i][1]);
                } else {
                    res.push_back(intervals[i]);
                    index++;
                }
                // 否则，当前区间需要考虑插入区间，有四种情况
            } else {
                if (res[index][1] >= newInterval[0] &&
                    newInterval[1] >= intervals[i][0]) {
                    res[index][1] = max(max(res[index][1], newInterval[1]),
                                        intervals[i][1]);
                } else if (res[index][1] >= newInterval[0] &&
                           newInterval[1] < intervals[i][0]) {
                    res[index][1] = max(res[index][1], newInterval[1]);
                    res.push_back(intervals[i]);
                    index++;
                } else if (res[index][1] < newInterval[0] &&
                           newInterval[1] >= intervals[i][0]) {
                    newInterval[1] = max(newInterval[1], intervals[i][1]);
                    res.push_back(newInterval);
                    index++;
                } else {
                    res.push_back(newInterval);
                    index++;
                    res.push_back(intervals[i]);
                    index++;
                }
            }
        }
        return res;
    }
};