#include <string>

using namespace std;

/**
 * 题目12：整数转罗马数字
 *
 */
class LeeCode12 {
   public:
    /**
     * 思路：贪心算法
     */
    string intToRoman(int num) {
        int nums[] = {1000, 900, 500, 400, 100, 90, 50, 40, 10, 9, 5, 4, 1};
        string str[] = {"M",  "CM", "D",  "CD", "C",  "XC", "L",
                        "XL", "X",  "IX", "V",  "IV", "I"};
        string res = "";
        int index = 0;
        while (index < 13) { // 从基数最大的数字开始依次比较
            while (num >= nums[index]) { // 依次减去当前基数中最大的值
                num -= nums[index];
                res += str[index];
            }

            index++;
        }
        return res;
    }
};