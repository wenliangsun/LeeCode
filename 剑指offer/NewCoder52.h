#include <string>

using namespace std;

/**
 * 题目52：正则表达式匹配
 * 模式中的字符'.'表示任意一个字符，而'*'表示它前面的字符可以出现任意次（包含0次）
 * 字符串"aaa"与模式"a.a"和"ab*ac*a"匹配，但是与"aa.a"和"ab*a"均不匹配
 */
class NewCoder52 {
   public:
    /**
     * 思路：
     *
     *
     *
     */
    bool match(char* str, char* pattern) {
        if (*str == '\0' && *pattern == '\0') {
            return true;
        }
        if (*str != '\0' && *pattern == '\0') {
            return false;
        }
        if (*(pattern + 1) != '\0' && *(pattern + 1) == '*') {
            if ((*str != '\0' && *str == *pattern) ||
                (*pattern == '.' && *str != '\0')) {
                return match(str, pattern + 2) || match(str + 1, pattern + 2) ||
                       match(str + 1, pattern);
            } else {
                return match(str, pattern + 2);
            }
        }
        if ((*str != '\0' && *str == *pattern) ||
            (*pattern == '.' && *str != '\0')) {
            return match(str + 1, pattern + 1);
        }
        return false;
    }
};
