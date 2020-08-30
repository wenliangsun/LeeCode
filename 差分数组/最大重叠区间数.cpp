#include <bits/stdc++.h>

using namespace std;

/**
 * 小猿非常热爱学习，所以他在猿辅导上购买了N节课来提升自己，每节课有一个开始时间SS和结束时间E（S和E均用正整数表示）。
 * 买完课程后，粗心的小袁发现这些课程之间有些时间冲突，幸好小猿有一种“一心多用”的超能力，
 * 能同时兼顾K节课上课。当然是K越大，使用这种能力就越累。请问小猿最少需要一心几用，才能上完所有他买的课程呢？
 * N <= 2000000
 * 
 * 猿辅导笔试，力扣会议室II
 */

class Solution{
    public:
    /**
     * 采用差分数组
     * 遍历时间区间，对于起始时间，映射值自增1，对于结束时间，映射值自减1，
     * 然后定义结果变量 res，和房间数 rooms，遍历 TreeMap，时间从小到大，房间数每次加上映射值，
     * 然后更新结果 res，遇到起始时间，映射是正数，则房间数会增加，如果一个时间是一个会议的结束时间，
     * 也是另一个会议的开始时间，则映射值先减后加仍为0，并不用分配新的房间，而结束时间的映射值为负数更不会增加房间数。
     */
    int minHeart(vector<vector<int>>& courses) {
        map<int, int> hash;
        for (auto c : courses) {
            hash[c[0]]++;
            hash[c[1]]--;
        }
        int res = 0, rooms = 0;
        for (auto item : hash) res = max(res, rooms += item.second);
        return res;
    }

    /**
     * 使用最小堆
     * 这种方法先把所有的时间区间按照起始时间排序，然后新建一个最小堆，开始遍历时间区间，
     * 如果堆不为空，且首元素小于等于当前区间的起始时间，去掉堆中的首元素，把当前区间的结束时间压入堆，
     * 由于最小堆是小的在前面，那么假如首元素小于等于起始时间，说明上一个会议已经结束，
     * 可以用该会议室开始下一个会议了，所以不用分配新的会议室，遍历完成后堆中元素的个数即为需要的会议室的个数。
     */
    int minHeart2(vector<vector<int>>& courses) {
        sort(courses.begin(), courses.end());
        priority_queue<int, vector<int>, greater<int>> q;
        int res = 0;
        for (auto c : courses) {
            // if (q.size() && q.top() <= c[0]) q.pop();
            // q.push(c[1]);

            while (q.size() && q.top() <= c[0]) q.pop();
            q.push(c[1]);
            res = max(res, (int)q.size());
        }
        return res;
        // return q.size();
    }

    /**
     * 用两个一维数组来做，分别保存起始时间和结束时间，然后各自排个序，定义结果变量 res 和结束时间指针 endpos，
     * 然后开始遍历，如果当前起始时间小于结束时间指针的时间，则结果自增1，反之结束时间指针自增1，
     * 这样可以找出重叠的时间段，从而安排新的会议室
     */
    int minHeart3(vector<vector<int>>& courses) {
        vector<int> start, end;
        for (auto c : courses) {
            start.push_back(c[0]);
            end.push_back(c[1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        int res = 0, endpos = 0;
        for (int i = 0; i < courses.size(); i++) {
            if (start[i] < end[endpos]) res++;
            else endpos++;
        }
        return res;
    }
};

int main() {
    Solution s = Solution();
    vector<vector<int>> cou = {{1, 4}, {1, 2}, {2, 3}, {3, 4}};
    int res = s.minHeart3(cou);
    cout << res << endl;
    return 0;
}