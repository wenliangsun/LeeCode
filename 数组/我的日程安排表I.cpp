#include <bits/stdc++.h>

using namespace std;

/**
 * 题目729：我的日程安排表I
 */

class MyCalendar {
   public:
    vector<pair<int, int>> data;
    MyCalendar() {}

    /**
     * 暴力
     */
    bool book(int start, int end) {
        for (auto item : data) {
            if (item.first < end && item.second > start) return false;
        }
        data.push_back({start, end});
        return true;
    }
};