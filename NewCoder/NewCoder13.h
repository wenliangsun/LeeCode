//
// Created by wenliangsun on 2020/2/7.
//

#ifndef C__ALGORITHM_NEWCODER13_H
#define C__ALGORITHM_NEWCODER13_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER13_H
using std::vector;

/**
 * 题目：调整数组顺序使奇数位于偶数前面
 * 输入一个整数数组，实现一个函数来调整该数组中数字的顺序，使得所有的奇数位于前面，所有的偶数位于后面，
 * 并保证奇数和奇数之间，偶数和偶数之间相对位置不变。
 */
class NewCoder13 {
public:
    /**
     * 思路1：保证奇数和奇数、偶数和偶数之间的相对位置不变，采用冒泡排序的思想。
     * @param array
     */
    void reOrderArray01(vector<int> &array) {
        int flag = 1;
        for (int i = 0; i < array.size(); ++i) {
            if (flag == 0)
                break;
            flag = 0;
            for (int j = 0; j < array.size() - 1 - i; ++j) { // 注意这儿需要-1
                if (array[j] % 2 == 0 && array[j + 1] % 2 == 1) { // 如果前偶后奇，则交换
                    int temp = array[j + 1];
                    array[j + 1] = array[j];
                    array[j] = temp;
                    flag = 1;
                }
            }
        }
    }

    /**
     * 如果没有要求保证奇数和奇数、偶数和偶数之间的相对位置不变
     * 采用两个指针分别来处理奇数和偶数，即第一个指针控制奇数，第二个指针控制偶数。
     * @param array
     */
    void reOrderArray02(vector<int> &array) {
        int pOdd = 0; // 第一个指针
        int pEven = array.size() - 1; // 第二个指针
        while (pOdd < pEven) { // 移动指针条件
            while (pOdd < pEven && array[pOdd] % 2 == 1) // 向后移动找偶数
                pOdd++;
            while (pOdd < pEven && array[pEven] % 2 == 0) // 向前移动找奇数
                pEven--;
            if (pOdd < pEven) { // 如果前偶后奇，交换
                int temp = array[pEven];
                array[pEven] = array[pOdd];
                array[pOdd] = temp;
            }
        }
    }
};