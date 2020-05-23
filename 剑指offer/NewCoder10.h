//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER10_H
#define C__ALGORITHM_NEWCODER10_H

#endif //C__ALGORITHM_NEWCODER10_H

/**
 * 题目10：矩形覆盖
 * 我们可以用2*1的小矩形横着或者竖着去覆盖更大的矩形。请问用n个2*1的小矩形无重叠地覆盖一个2*n的大矩形，总共有多少种方法？
 */
class NewCoder10 {
public:
    /**
     * 实际上还是斐波拉契数列！
     * @param number
     * @return
     */
    int rectCover(int number) {
        if (number == 1)
            return 1;
        else if (number == 2)
            return 2;
        else
            return rectCover(number - 1) + rectCover(number - 2);
    }
};