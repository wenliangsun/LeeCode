#include <bits/stdc++.h>

using namespace std;

/** 
 * 数据流中的中位数
 */

class MedianFinder {
   public:
    /** initialize your data structure here. */
    priority_queue<int, vector<int>, greater<int>> minq;  // 最小堆
    priority_queue<int, vector<int>, less<int>> maxq;     // 最大堆
    int cnt = 0;                                          //计数
    MedianFinder() { cnt = 0; }

    void addNum(int num) {
        cnt++;
        maxq.push(num);         // 先进大顶堆
        minq.push(maxq.top());  // 再进小顶堆
        maxq.pop();
        if (cnt & 1) {
            maxq.push(minq.top());
            minq.pop();
        }
    }

    double findMedian() {
        if (cnt & 1)  // 如果是奇数，直接返回最大堆堆顶元素
            return maxq.top();
        else  //否则是最大堆和最小堆堆顶元素的均值
            return ((double)maxq.top() + minq.top()) / 2;
    }
};
