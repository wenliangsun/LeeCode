//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER20_H
#define C__ALGORITHM_NEWCODER20_H

#include <stack>

#endif //C__ALGORITHM_NEWCODER20_H
using std::stack;

/**
 * 题目20：包含min函数的栈
 * 定义栈的数据结构，请在该类型中实现一个能够得到栈中所含最小元素的min函数(时间复杂度应为O(1))
 */
class NewCoder20 {
public:
    stack<int> tdata;
    stack<int> tmin;

    void push(int value) {
        tdata.push(value);
        if (tmin.empty()) {
            tmin.push(value);
        }
        if (!tmin.empty()) {
            if (tmin.top() > value)
                tmin.push(value);
        }
    }

    void pop() {
        if (tdata.top() == tmin.top()) {
            tmin.pop();
        }
        tdata.pop();
    }

    int top() {
        return tdata.top();
    }

    int min() {
        return tmin.top();
    }

};