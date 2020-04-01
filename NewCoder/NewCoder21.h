//
// Created by wenliangsun on 2020/2/9.
//

#ifndef C__ALGORITHM_NEWCODER21_H
#define C__ALGORITHM_NEWCODER21_H

#include <vector>
#include <stack>

#endif //C__ALGORITHM_NEWCODER21_H
using std::vector;
using std::stack;

/**
 * 题目21：栈的压入、弹出序列
 * 输入两个整数序列，第一个序列表示栈的压入顺序，请判断第二个序列是否可能为该栈的弹出顺序。
 * 假设压入栈的所有数字均不相等。例如序列1,2,3,4,5是某栈的压入顺序，
 * 序列4,5,3,2,1是该压栈序列对应的一个弹出序列，但4,3,5,1,2就不可能是该压栈序列的弹出序列。
 * （注意：这两个序列的长度是相等的）
 */
class NewCoder21 {
public:
    /**
     * 思路：借助辅助栈进行入栈出栈操作：
     * 1）依次对给的入栈序列入栈，并同时判断栈顶元素是否与出栈序列中元素相同；
     * 2）如果栈顶元素和出栈序列的元素相同，则出栈，出栈序列的指针后移，直到栈顶元素和出栈序列不同时，开始入栈。
     * @param pushV
     * @param popV
     * @return
     */
    bool IsPopOrder(vector<int> pushV, vector<int> popV) {
        stack<int> stk; // 辅助栈
        int popIndex = 0; // 出栈序列的指针
        for (int i = 0; i < pushV.size(); ++i) {
            stk.push(pushV[i]); // 入栈
            while (!stk.empty() && stk.top() == popV[popIndex]) { // 判断栈顶元素是否和出栈元素相同
                stk.pop();
                popIndex++;
            }
        }
        return stk.empty();
    }
};