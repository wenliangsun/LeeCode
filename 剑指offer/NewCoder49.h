#include <string>

using namespace std;

/**
 * 题目49：把字符串转换成整数
 * 将一个字符串转换成一个整数，要求不能使用字符串转换整数的库函数。
 * 数值为0或者字符串不是一个合法的数值则返回0。
 */
class NewCoder49 {
   public:
    int StrToInt(string str) {
        if (str.empty()) {
            return 0;
        }
        int res = 0;  // 注意int 类型的字节数！！！ 不同平台有差别
        bool flag = true;  // 记录正负数
        if (str[0] == '-') {
            flag = false;
        }
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '+' || str[i] == '-') {  // 考虑第一个字符是符号
                continue;
            }
            if (str[i] < 48 || str[i] > 57) {  // 排除非法字符
                return 0;
            }
            res = res * 10 + str[i] - 48;       // 计算数字
            if (res < 0 && res != 0xFFFFFFF) {  // 判断内存是否溢出
                return 0;
            }
            if (flag && res < 0) {
                return 0;
            }
        }
        return flag ? res : -res;
    }
};