//
// Created by wenliangsun on 2020/2/6.
//

#ifndef C__ALGORITHM_NEWCODER06_H
#define C__ALGORITHM_NEWCODER06_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER06_H
using std::vector;

/**
 * 题目6：旋转数组中的最小值
 * 把一个数组最开始的若干个元素搬到数组的末尾，我们称之为数组的旋转。输入一个非递减排序的数组的一个旋转，输出旋转数组的最小元素。
 * 例如数组{3,4,5,1,2}为{1,2,3,4,5}的一个旋转，该数组的最小值为1。
 * NOTE：给出的所有元素都大于0，若数组大小为0，请返回0
 */
class NewCoder06 {
public:
    /**
     * 思路1：直接遍历数组寻找最小数字
     * 但是没有充分利用题目中排序数组的信息，这在面试的时候并不能达到好的面试效果
     * 考虑：一旦涉及到排序数组的时候，优先考虑二分查找方法，对二分查找进行灵活应用！
     * 时间复杂度：O(n)
     * @param rotateArray
     * @return
     */
    int minNumberInRotateArray01(vector<int> rotateArray) {
        int minNumber = rotateArray[0];
        for (int i : rotateArray) {
            if (i > minNumber)
                continue;
            else {
                minNumber = i;
            }
        }
        return minNumber;
    }

    /**
     * 思路2:利用二分查找的思路，考虑旋转数组是把前面一部分拿到了尾部，我们利用二分法的思路，设置两个指针分别指向首尾。
     * 1）第一个指针的值大于等于第二个指针的值(有例外)，然后获得中间位置的值。
     * 2）如果中间位置的值位于前面部分的递增数组中，则最小数应该位于中间位置的后面，将第一个指针设置为中间位置，缩短了搜索区间，
     * 3）如果中间位置的值位于后面部分的递增数组中，则最小数应该位于中间位置的前面，将第二个指针设置为中间位置，缩短了搜索区间；
     * 4) 这样使得第一个指针始终出钱前面的递增数组中，第二个指针始终处于后面的递增数组中，当两个指针相邻时，第二个指针所在位置即为最小数；
     * 5）特殊情况：(1)当数组中的第一个指针，第二个指针和中间位置相等时，无法确定最小值位于哪个区间，只能暴力遍历！！！
     *             (2)当数组本来就是排序数组，即0个元素移到尾部，我们开始的时候就将第一个数设置为最小数来解决这一问题。
     * @param rotateArray
     * @return
     */
    int minNumberInRotateArray02(vector<int> rotateArray) {
        int index1 = 0; // 第一个指针
        int index2 = rotateArray.size() - 1; // 第二个指针
        int indexMid = index1;  // 考虑0个元素移到尾部
        while (rotateArray[index1] >= rotateArray[index2]) {
            if ((index2 - index1) == 1) { //终止条件 即两个指针相邻
                indexMid = index2; // 第二个指针所指即为最小值
                break;
            }
            indexMid = (index1 + index2) / 2;
            if (rotateArray[index1] == rotateArray[index2] && rotateArray[index1] == rotateArray[indexMid])
                return minNumber(rotateArray, index1, index2); // 特殊情况
            if (rotateArray[indexMid] >= rotateArray[index1]) // 缩小区间
                index1 = indexMid;
            if (rotateArray[indexMid] <= rotateArray[index2]) // 缩小区间
                index2 = indexMid;
        }
        return rotateArray[indexMid];
    }

private:
    int minNumber(vector<int> rotateArray, int index1, int index2) {
        int minnum = rotateArray[index1];
        for (int i = index1; i <= index2; ++i) {
            if (rotateArray[i] < minnum) {
                minnum = rotateArray[i];
            }
        }
        return minnum;
    }
};