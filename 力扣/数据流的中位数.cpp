#include <bits/stdc++.h>

using namespace std;

/**
 * 题目295：数据流中的中位数
 */

class MedianFinder {
    int cnt = 0;  // 记录读取的数字个数
    priority_queue<int, vector<int>, less<int>> maxq;     // 最大堆
    priority_queue<int, vector<int>, greater<int>> minq;  // 最小堆

   public:
    /** initialize your data structure here. */
    MedianFinder() { cnt = 0; }

    void addNum(int num) {
        cnt++;
        // 先读进最大堆
        maxq.push(num);
        // 然后把最大堆的堆顶元素给最小堆
        minq.push(maxq.top());
        maxq.pop();
        // 如果是奇数的话，把最小堆的堆顶元素给最大堆
        if (cnt & 1) {
            maxq.push(minq.top());
            minq.pop();
        }
    }

    double findMedian() {
        // 如果是奇数，则中位数就是最大堆堆顶元素
        if (cnt & 1) return maxq.top();
        // 如果是偶数，则中位数是最大堆和最小堆堆顶元素的均值
        return (double(maxq.top()) + minq.top()) / 2;
    }
};