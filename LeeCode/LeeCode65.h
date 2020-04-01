#include <string>

using namespace std;

/**
 * 题目65：有效数字
 */
class LeeCode65 {
   public:
    /**
     * 思路：一个位置一个位置判断
     * 时间复杂度：O(n)
     * 空间复杂度：O(1)
     */
    bool isNumber(string s) {
        if (s.empty()) {
            return false;
        }
        int index = 0;  // 字符串索引
        // 去除左边空格
        while (s[index] == ' ') {
            index++;
        }
        // 判断符号位
        if (s[index] == '+' || s[index] == '-') {
            index++;
        }
        int n_dot;
        int n_num;
        // 判断数字和小数点
        for (n_dot = 0, n_num = 0;
             (s[index] >= '0' && s[index] <= '9') || s[index] == '.'; index++) {
            s[index] == '.' ? n_dot++ : n_num++;
        }
        // 数字和小数点不符合的情况
        if (n_dot > 1 || n_num < 1) {
            return false;
        }
        // 如果字符串中有指数e
        if (s[index] == 'e' || s[index] == 'E') {
            index++;
            // 指数之后的符号位
            if (s[index] == '+' || s[index] == '-') {
                index++;
            }
            int n_num = 0;
            // e之后只能是数字，不能是小数点
            for (; s[index] >= '0' && s[index] <= '9'; index++) {
                n_num++;
            }
            // e之后必须要有数字
            if (n_num < 1) {
                return false;
            }
        }
        // 去除右边空格
        while (s[index] == ' ') {
            index++;
        }
        // 如果字符串到末尾则是数字
        return index == s.size();
    }

    /**
     * 思路：一个位置一个位置判断是否符合
     * 这个代码有问题，牛客可以通过。
     */
    bool isNumber2(string s) {
        if (s.empty()) {
            return false;
        }
        s.erase(s.find_last_not_of(" ") + 1);
        s.erase(0, s.find_first_not_of(" "));
        int index = 0;
        // 判断符号位
        if (s[index] == '+' || s[index] == '-') {
            index++;
        }
        // 如果符号位完了之后字符串没了，则返回false
        if (index >= s.size()) {
            return false;
        }
        bool dot = false;   // 标记是否有小数点
        bool hasE = false;  // 标记是否有指数e
        // 遍历剩余字符串
        while (index < s.size()) {
            // 符号位之后判断是否是数组
            if (s[index] >= '0' && s[index] <= '9') {
                index++;
                // 然后判断是否包含小数点
            } else if (s[index] == '.') {
                if (dot || hasE || s.size() == 1) {
                    return false;
                }
                index++;
                dot = true;
                // 接着判断是否包含指数e
            } else if (s[index] == 'e' || s[index] == 'E') {
                if (hasE || index == 0) {
                    return false;
                }
                index++;
                hasE = true;
                // 判断指数位之后的符号位
                if (s[index] == '+' || s[index] == '-') {
                    index++;
                }
                // 判断符号位之后字符串是否没了
                if (index >= s.size()) {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};