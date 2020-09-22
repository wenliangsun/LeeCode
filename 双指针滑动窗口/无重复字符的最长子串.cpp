#include <map>
#include <string>
#include <unordered_map>
#include <unordered_set>

using namespace std;

/**
 * 题目3：无重复字符的最长子串
 * 给定一个字符串，请你找出其中不含有重复字符的 最长子串 的长度。
 */
class LeeCode03 {
   public:
    // 双指针 太秀了！！！
    int lengthOfLongestSubstring4(string s) {
        unordered_map<char, int> hash;
        int res = 0;
        for (int i = 0, j = 0; i < s.size(); i++) {
            hash[s[i]]++;
            while (hash[s[i]] > 1) hash[s[j++]]--;
            res = max(res, i - j + 1);
        }
        return res;
    }

    /**
     * 思路: 利用hash表来判断字符是否重复
     */
    int lengthOfLongestSubstring(string s) {
        if (s.empty()) {
            return 0;
        }
        int res = 0;
        map<char, int> m;
        for (int i = 0, j = 0; j < s.size(); j++) {
            if (m.find(s[j]) != m.end()) {
                i = m[s[j]] < i ? i : m[s[j]];
            }
            // cout << i << "---" << j << endl;
            res = res > (j - i + 1) ? res : (j - i + 1);
            m[s[j]] = j + 1;
        }
        return res;
    }

    /**
     * 思路：滑动窗口法
     */
    int lengthOfLongestSubstring2(string s) {
        if (s.size() == 0) {
            return 0;
        }
        unordered_set<char> set;
        int maxStr = 0;
        int left = 0;
        for (int right = 0; right < s.size(); right++) {
            while (set.find(s[right]) != set.end()) {
                set.erase(s[left]);
                left++;
            }
            maxStr = max(maxStr, right - left + 1);
            set.insert(s[right]);
        }
        return maxStr;
    }
    /**
     * 思路：滑动窗口模板
     */
    int lengthOfLongestSubstring3(string s) {
        if (s.size() == 0) {
            return 0;
        }
        int maxStr = 0;
        int left = 0;
        int right = 0;
        unordered_map<char, int> window;
        while (right < s.size()) {
            char c = s[right];
            window[c] = window.count(c) ? window[c] + 1 : 1;
            right++;
            while (window[c] > 1) {
                char c = s[left];
                window[c]--;
                left++;
            }
            maxStr = max(maxStr, right - left);
        }
        return maxStr;
    }
};