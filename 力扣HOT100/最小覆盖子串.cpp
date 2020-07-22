#include <map>
#include <string>

using namespace std;

/**
 * 题目76：最小覆盖子串
 */
class LeeCode76 {
   public:
    /**
     * 思路：滑动窗口法
     * (1)使用双指针技巧，初始化left和right为0，把[left,right]称为一个窗口；
     * (2)先不断增加right使得窗口满足字符串需求；
     * (3)此时停止right的增加，而是增加left以缩小窗口，直至窗口中的字符串不在符合要求，每次增加left，都要更新一轮的结果。
     * (4)重复(2)(3)直至right到达字符串的尽头
     */
    string minWindow(string s, string t) {
        map<char, int> need;    // 需求字符串
        map<char, int> window;  //滑动窗口
        // 生成需求字符串的map
        for (char c : t) {
            if (need.count(c)) {
                need[c]++;
            } else {
                need[c] = 1;
            }
        }
        int left = 0;          // 左指针
        int right = 0;         // 右指针
        int start = 0;         // 字符串开始位置
        int minLen = INT_MAX;  // 最小长度
        int matched = 0;       // 匹配的字符数
        while (right < s.size()) {
            char c = s[right];
            // 如果需求字符串中包含则在入窗口
            if (need.count(c)) {
                if (window.count(c)) {
                    window[c]++;
                } else {
                    window[c] = 1;
                }
                // 如果窗口中的当前字符满足需求，则匹配计数
                if (window[c] == need[c]) {
                    matched++;
                }
            }
            // 窗口右移
            right++;
            // 如果匹配的字符数满足需求，则增加left缩减窗口
            while (matched == need.size()) {
                // 更新最小长度和开始位置
                if (right - left < minLen) {
                    start = left;
                    minLen = right - left;
                }
                char c = s[left];
                // 缩小窗口
                if (need.count(c)) {
                    window[c]--;
                    if (window[c] < need[c]) {
                        matched--;
                    }
                }
                left++;
            }
        }
        return minLen == INT_MAX ? "" : s.substr(start, minLen);
    }
};