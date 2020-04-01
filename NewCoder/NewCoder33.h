//
// Created by wenliangsun on 2020/2/13.
//

#ifndef C__ALGORITHM_NEWCODER33_H
#define C__ALGORITHM_NEWCODER33_H

#endif //C__ALGORITHM_NEWCODER33_H

/**
 * 题目33：丑数
 * 把只包含质因子2、3和5的数称作丑数（Ugly Number）。
 * 例如6、8都是丑数，但14不是，因为它包含质因子7。
 * 习惯上我们把1当做是第一个丑数。求按从小到大的顺序的第N个丑数。
 */
class NewCoder33 {
public:
    /**
     * 思路1：对从1到N的数字依次判断是否是丑数
     * @param index
     * @return
     */
    int GetUglyNumber_Solution01(int index) {
        int count = 0;
        int num = 0;
        while (count < index) {
            num++;
            if (isUgly(num))
                count++;
        }
        return num;
    }

    /**
     * 思路：利用空间换时间，使用一个数组来保存所有的丑数。
     * @param index
     * @return
     */
    int GetUglyNumber_Solution02(int index) {
        int *uglyNumbers = new int[index];
        uglyNumbers[0] = 1;
        int numberIndex = 1;
        int *pMultiply2 = uglyNumbers;
        int *pMultiply3 = uglyNumbers;
        int *pMultiply5 = uglyNumbers;
        while (numberIndex < index) {
            uglyNumbers[numberIndex] = minNumber(*pMultiply2 * 2, *pMultiply3 * 3, *pMultiply5 * 5);
            while (*pMultiply2 * 2 <= uglyNumbers[numberIndex])
                pMultiply2++;
            while (*pMultiply3 * 3 <= uglyNumbers[numberIndex])
                pMultiply3++;
            while (*pMultiply5 * 5 <= uglyNumbers[numberIndex])
                pMultiply5++;
            numberIndex++;
        }
        return uglyNumbers[numberIndex - 1];
    }

    int minNumber(int a, int b, int c) {
        int temp = a < b ? a : b;
        return temp < c ? temp : c;
    }

    bool isUgly(int number) {
        while (number % 2 == 0)
            number /= 2;
        while (number % 3 == 0)
            number /= 3;
        while (number % 5 == 0)
            number /= 5;
        return number == 1;
    }
};