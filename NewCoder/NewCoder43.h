#include <string>

using namespace std;

/**
 * 题目43：左旋转字符串
 * 对于一个给定的字符序列S，请你把其循环左移K位后的序列输出。
 * 例如，字符序列S=”abcXYZdef”,要求输出循环左移3位后的结果，即“XYZdefabc”。
 */
class NewCoder43 {
   public:
    /**
     *
     * 思路：数字n将字符串分为两个子串
     * (1) 先翻转左子串
     * (2) 再翻转右子串
     * (3) 最后翻转整个字符串
     * @param str
     * @param n
     * @return
     */
    string LeftRotateString(string str, int n) {
        if (str.empty()) {
            return str;
        }
        str = reverser(str, 0, n - 1);           // 翻转左子串
        str = reverser(str, n, str.size() - 1);  // 翻转右子串
        str = reverser(str, 0, str.size() - 1);  // 翻转整个字符串
        return str;
    }

    /**
     * 翻转字符串
     * @param str
     * @param start
     * @param end
     * @return
     */
    string reverser(string str, int start, int end) {
        while (start < end) {
            char temp = str[start];
            str[start] = str[end];
            str[end] = temp;
            start++;
            end--;
        }
        return str;
    }
};