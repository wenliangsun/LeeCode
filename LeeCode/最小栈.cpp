#include <bits/stdc++.h>

using namespace std;

/**
 * 题目155：最小栈
 * 设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
 */

class MinStack {
    stack<int> stkmin, stkdata;

   public:
    /** initialize your data structure here. */
    MinStack() {
        while (stkmin.size()) stkmin.pop();
        while (stkdata.size()) stkdata.pop();
    }

    void push(int x) {
        stkdata.push(x);
        if (stkmin.empty()) {
            stkmin.push(x);
        } else {
            if (stkmin.top() > x)
                stkmin.push(x);
            else
                stkmin.push(stkmin.top());
        }
    }

    void pop() {
        stkmin.pop();
        stkdata.pop();
    }

    int top() { return stkdata.top(); }

    int getMin() { return stkmin.top(); }
};