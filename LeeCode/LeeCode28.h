#include <string>

using namespace std;

/**
 * 实现strStr()
 */
class LeeCode28 {
   public:
    /**
     * 思路：双指针法
     */
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        for (int i = 0; i < haystack.size(); i++) {
            int j = 0;
            for (; j < needle.size(); j++) {  // 从当前开始匹配子串
                if (haystack[i + j] != needle[j]) {
                    break;
                }
            }
            if (j == needle.size()) {  // 如果子串匹配完，则返回当前索引
                return i;
            }
        }
        return -1;
    }

    /**
     * 库函数法
     */
    int strStr02(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        int res = haystack.find(needle);
        return res;
    }

    /**
     * KMP法
     */
    int strStr03(string haystack, string needle) {}
};