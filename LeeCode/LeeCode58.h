#include <string>

using namespace std;

/**
 * 题目58：最后一个单词的长度
 */
class LeeCode58 {
   public:
    /**
     * 思路：从右向左遍历
     */
    int lengthOfLastWord(string s) {
        if (s.empty()) {
            return 0;
        }
        int right = s.size() - 1;
        // 寻找单词有边界
        while (right >= 0 && s[right] == ' ') {
            right--;
        }
        int left = right;
        // 寻找单词左边界
        while (left >= 0 && s[left] != ' ') {
            left--;
        }
        return right - left;
    }
};