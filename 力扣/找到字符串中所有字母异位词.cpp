#include <iostream>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 题目438：找到字符串中所有字母异位词
 */
class LeeCode438 {
   public:
    /**
     * 思路：滑动窗口法
     */
    vector<int> findAnagrams(string s, string p) {
        vector<int> res;
        int left = 0;
        int right = 0;
        unordered_map<char, int> temp;
        unordered_map<char, int> window;
        for (int i = 0; i < p.size(); i++) {
            temp[p[i]]++;
        }
        int matched = 0;
        while (right < s.size()) {
            char c = s[right];
            if (temp.count(c)) {
                // 向右扩大窗口
                window[c]++;
                if (window[c] == temp[c]) {
                    matched++;
                }
            }
            right++;
            while (matched == temp.size()) {
                if (right - left == p.size()) {
                    res.push_back(left);
                }
                char c = s[left];
                if (temp.count(c)) {
                    // 左侧缩小窗口
                    window[c]--;
                    if (window[c] < temp[c]) {
                        matched--;
                    }
                }
                left++;
            }
        }
        return res;
    }
};

int main() {
    string s = "abcbcbacbcdacb";
    string p = "abc";
    LeeCode438 code = LeeCode438();
    vector<int> res = code.findAnagrams(s, p);
    for (int i = 0; i < res.size(); i++) {
        cout << res[i] << endl;
    }
}
