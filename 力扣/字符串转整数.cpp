#include <climits>
#include <string>

using namespace std;

/**
 * 题目8：字符串转整数
 * 考虑特征用例：
 * "  +42" --> 42
 * "+-2" --> 0
 * "+123" --> 123
 * "-123" --> -123
 * "asbce" --> 0
 * "+1234abc" --> 123
 * "+12 34" --> 12
 * "+2147483647" --> 2147483647
 * "+2147483648" --> 2147483647
 * "-2147483648" --> -2147483648
 * "-2147483649" --> -2147483648
 */
class LeeCode08 {
   public:
    int myAtoi(string str) {
        // 异常情况
        if (str.empty()) {
            return 0;
        }
        int res = 0;    //记录结果
        int sign = 1;   // 符号标志
        int index = 0;  // 遍历字符串的指针

        while (index < str.size()) {  // 过滤字符串前面的空格
            if (str[index] == ' ') {
                index++;
            } else {
                break;
            }
        }
        if (index < str.size()) {  // 接着判断是否有符号位
            if (str[index] == '-') {
                sign = -1;
                index++;
            } else if (str[index] == '+') {
                sign = 1;
                index++;
            }
        }
        // 之后的全部应该是数字，不是数字的话，跳出循环
        while (index < str.size()) {
            char c = str[index];
            if (c < '0' || c > '9') {  // 排除异常字符
                break;
            }
            int temp = sign * (c - '0');  // 给每一个数字都乘以符号
            // 正数时溢出情况判断
            if (res > INT_MAX / 10 || (res == INT_MAX / 10 && temp > 7)) {
                return INT_MAX;
            }
            // 负数时溢出情况判断
            if (res < INT_MIN / 10 || (res == INT_MIN / 10 && temp < -8)) {
                return INT_MIN;
            }
            res = res * 10 + temp;
            index++;
        }
        return res;
    }
};