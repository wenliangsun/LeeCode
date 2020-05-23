#include <vector>

using namespace std;

/**
 * 题目64：滑动窗口的最大值
 *  给定一个数组和滑动窗口的大小，找出所有滑动窗口里数值的最大值。
 * 例如，如果输入数组{2,3,4,2,6,2,5,1}及滑动窗口的大小3，
 * 那么一共存在6个滑动窗口，他们的最大值分别为{4,4,6,6,6,5}；
 * 针对数组{2,3,4,2,6,2,5,1}的滑动窗口有以下6个： {[2,3,4],2,6,2,5,1}，
 * {2,[3,4,2],6,2,5,1}， {2,3,[4,2,6],2,5,1}， {2,3,4,[2,6,2],5,1}，
 * {2,3,4,2,[6,2,5],1}， {2,3,4,2,6,[2,5,1]}。
 */
class NewCoder64 {
   public:
    /**
     * 思路：首先寻找第一个窗口的最大值，然后每次向后移动一位的时候，
     * 判断左侧移出去的数字是否是当前窗口的最大值，
     * 1.若不是最大值，则将右侧进入的数字与最大值进行比较，
     *      (1)若大于最大值，则更新最大值，将最大值添加到结果中;
     *      (2) 若小于最大值，则将最大值添加到结果中。
     * 2.若是最大值，则重新寻找下一个窗口的最大值。
     *  
     */
    vector<int> maxInWindows(const vector<int>& num, unsigned int size) {
        vector<int> res;
        if (num.size() < size || size <= 0) {
            return res;
        }
        int p1 = 0;
        int p2 = size - 1;
        int maxNum = maxNumber(num, p1, p2); // 寻找窗口中的最大值
        res.push_back(maxNum);
        p1++;
        p2++;
        while (p2 < num.size()) {
            if (num[p1 - 1] != maxNum) { // 移出去的不是最大值
                if (num[p2] > maxNum) { // 判断移进来的数字是否大于最大值
                    maxNum = num[p2];
                    res.push_back(maxNum);
                } else {
                    res.push_back(maxNum);
                }
            } else { // 移出去的是最大值，则重新寻找新窗口的最大值
                maxNum = maxNumber(num, p1, p2);
                res.push_back(maxNum);
            }
            p1++;
            p2++;
        }
        return res;
    }

   private:
    int maxNumber(vector<int> num, int begin, int end) {
        int maxNum = num[begin];
        for (int i = begin; i <= end; i++) {
            if (num[i] > maxNum) {
                maxNum = num[i];
            }
        }
        return maxNum;
    }
};