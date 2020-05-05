#include <algorithm>
#include <queue>
#include <string>
#include <unordered_set>
#include <vector>

using namespace std;

/**
 * 题目127：单词接龙
 */

class Solution {
   public:
    int ladderLength(string b, string e, vector<string>& w) {
        unordered_set<string> s;
        for (auto str : w) s.insert(str);
        queue<string> q;
        q.push(b);
        int res = 0;
        while (q.size()) {
            int len = q.size();
            res++;
            for (int i = 0; i < len; i++) {
                string t = q.front();
                q.pop();
                if (t == e) return res;
                for (int i = 0; i < t.size(); i++) {
                    char ch = t[i];
                    // 如果是更换字符串中的一个字符，可以对每一个位置尝试所有的字符
                    for (char c = 'a'; c <= 'z'; c++) {
                        if (ch == c) continue;
                        t[i] = c;
                        if (s.find(t) != s.end()) {
                            q.push(t);
                            s.erase(t);
                        }
                    }
                    t[i] = ch;
                }
            }
        }
        return 0;
    }

    /**
     * 暴力BFS：超时
     */
    int ladderLength1(string b, string e, vector<string>& w) {
        if (w.empty() || find(w.begin(), w.end(), e) == w.end()) return 0;
        vector<bool> vis(w.size(), false);
        queue<string> q;
        q.push(b);
        int res = 0;
        while (q.size()) {
            int size = q.size();
            res++;
            for (int i = 0; i < size; i++) {
                string t = q.front();
                q.pop();
                for (int j = 0; j < w.size(); j++) {
                    if (vis[j]) continue;
                    if (!canConvert(t, w[j])) continue;
                    if (e == w[j]) return res + 1;
                    vis[j] = true;
                    q.push(w[j]);
                }
            }
        }
        return 0;
    }

    bool canConvert(string t, string w) {
        int cnt = 0;
        for (int i = 0; i < t.size(); i++) {
            if (t[i] != w[i]) cnt++;
            if (cnt > 1) return false;
        }
        return cnt == 1;
    }
};