//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER05_H
#define C__ALGORITHM_NEWCODER05_H

#include <stack>

#endif //C__ALGORITHM_NEWCODER05_H
using std::stack;

/**
 * 题目5：用两个栈实现队列
 * 用两个栈来实现一个队列，完成队列的Push和Pop操作。 队列中的元素为int类型。
 */
class NewCoder05 {
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        int temp;
        while (!stack1.empty()) {
            stack2.push(stack1.top());
            stack1.pop();
        }
        temp = stack2.top();
        stack2.pop();
        while (!stack2.empty()) {
            stack1.push(stack2.top());
            stack2.pop();
        }
        return temp;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};