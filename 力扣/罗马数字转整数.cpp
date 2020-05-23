#include <map>
#include <string>

using namespace std;

/**
 * 题目13：罗马数字转整数
 */
class LeeCode13 {
   public:
    /**
     * 思路：
     * 观察分析发现：只有在遇到特殊情况时，两个字符中左边的字符小于右边的字符，
     * 并且等于右边的字符代表的数减左边字符代表的数，如 CM = 1000-100 CD =
     * 500-100
     */
    int romanToInt(string s) {
        if (s.empty()) {
            return 0;
        }
        map<char, int> m = {{'I', 1},   {'V', 5},   {'X', 10},  {'L', 50},
                            {'C', 100}, {'D', 500}, {'M', 1000}};
        int res = 0;
        for (int i = 0; i < s.size() - 1; i++) {
            if (m[s[i]] < m[s[i + 1]]) {
                res -= m[s[i]];
            } else {
                res += m[s[i]];
            }
        }
        return res += m[s[s.size() - 1]];
    }
};