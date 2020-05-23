
/**
 * 题目53：表示数值的字符串
 * 请实现一个函数用来判断字符串是否表示数值（包括整数和小数）。
 * 例如，字符串"+100","5e2","-123","3.1416"和"-1E-16"都表示数值。
 * 但是"12e","1a3.14","1.2.3","+-5"和"12e+4.3"都不是。
 */
class NewCoder53 {
   public:
    /**
     * 思路：依次判断是否符合数字
     */
    bool isNumeric(char* string) {
        if (string == nullptr) {  // 如果是空指针，返回false
            return false;
        }
        if (*string == '+' || *string == '-') {  // 判断第一个位置是否是符号位
            string++;
        }
        if (*string == '\0') {  // 排除只有符号的字符串
            return false;
        }
        bool dot = false;          // 标记 . 是否出现
        bool hasE = false;         // 标记 e或E 是否出现
        while (*string != '\0') {  // 遍历字符串
            if (*string >= '0' && *string <= '9') {  // 数字
                string++;
            } else if (*string == '.') {  // 判断是否有 .
                // 此时分两种情况:(1)有点则直接返回false; (2)
                // 如果e或E已经出现，则直接返回false。
                if (dot || hasE) {
                    return false;
                }
                string++;
                dot = true;
            } else if (*string == 'e' || *string == 'E') {  // 是否是科学计数
                if (hasE) {  // 如果已经有e或E
                    return false;
                }
                string++;
                hasE = true;
                if (*string == '+' ||
                    *string == '-') {  // e之后的+-号只能是贴着E
                    string++;
                }
                if (*string == '\0') {  // 排除E之后只有+-号的情况
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
};