//
// Created by wenliangsun on 2020/2/5.
//

#ifndef C__ALGORITHM_DEMO_H
#define C__ALGORITHM_DEMO_H

#include <vector>

#endif //C__ALGORITHM_DEMO_H
using std::vector;

/**
 * 题目1: 二维数组中的查找
 * 在一个二维数组中（每个一维数组的长度相同），每一行都按照从左到右递增的顺序排序，
 * 每一列都按照从上到下递增的顺序排序。请完成一个函数，输入这样的一个二维数组和一个整数，
 * 判断数组中是否含有该整数。
 */
class NewCoder01 {
public:
    bool Find(int target, vector<vector<int> > array) {
        int rows = 0;
        int cols = array[0].size() - 1;
        while (rows < array.size() && cols >= 0) {
            if (target == array[rows][cols])
                return true;
            else if (target < array[rows][cols]) {
                cols--;
            } else {
                rows++;
            }
        }
        return false;
    }
};

