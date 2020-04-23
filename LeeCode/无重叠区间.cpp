#include <vector>

using namespace std;

/**
 * 题目435：无重叠区间
 */
class LeeCode435 {
   public:
    bool static compare(vector<int> v1, vector<int> v2) {
        return v1[1] < v2[2];
    }
    /**
     * 思路：先按区间右边界排序，然后找出数组中不重叠的区间数
     * 最后用数组表中的区间数减去不重叠的区间数即为要删除的区间数
     */
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.size() == 0) {
            return 0;
        }
        int count = 0;
        int x_end = intervals[0][1];
        for (int i = 1; i < intervals.size(); i++) {
            if (intervals[i][0] >= x_end) {
                count++;
                x_end = intervals[i][1];
            }
        }
        return intervals.size() - count;
    }
};