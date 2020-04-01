#include <string>

using namespace std;

/**
 * 题目44： 翻转单词顺序列
 * "student. a am I" --> "I am a student."
 */
class NewCoder44 {
   public:
    /**
     * 思路：先依次翻转每一个单词，然后对整个字符串进行翻转
     *
     * @param str
     * @return
     */
    string ReverseSentence(string str) {
        if (str.empty()) {
            return str;
        }
        int start = 0;
        int end = 0;
        while (start < str.size()) {  // 翻转每个单词
            if (str[start] == ' ') {
                start++;
                end++;
            } else if (end == str.size() || str[end] == ' ') {
                str = reverse(str, start, --end);
                start = ++end;
            } else {
                end++;
            }
        }
        str = reverse(str, 0, str.size() - 1);  // 翻转整个字符串
        return str;
    }

    string reverse(string str, int start, int end) {
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