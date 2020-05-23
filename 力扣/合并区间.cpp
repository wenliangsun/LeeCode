#include <algorithm>
#include <vector>

using namespace std;

/**
 * 题目56：合并区间
 */
class LeeCode56 {
   public:
    /**
     * 排序规则
     */
    bool static compare(vector<int> vec1, vector<int> vec2) {
        return vec1[0] < vec2[0];
    }
    /**
     * 思路：先对数组按照排序规则进行排序。
     * 然后判断
     * 时间复杂度：O(n)
     * 空间复杂度：O(区间长度)
     */
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>> res;
        if (intervals.size() == 0) {
            return res;
        }
        sort(intervals.begin(), intervals.end(), compare);
        res.push_back(intervals[0]);
        int index = 0;
        for (int i = 1; i < intervals.size(); i++) {
            // 判断结果数组中的区间是否重叠，若重叠则合并
            if (res[index][1] >= intervals[i][0]) {
                res[index][i] = max(res[index][1], intervals[i][1]);
                // 否则，将新区间添加进结果数组。
            } else {
                res.push_back(intervals[i]);
                index++;
            }
        }
        return res;
    }
};