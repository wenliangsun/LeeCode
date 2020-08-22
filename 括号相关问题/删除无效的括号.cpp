#include <bits/stdc++.h>

using namespace std;

/**
 * 题目301：删除无效的括号
 */

class Solution {
   public:
    /**
     * 深搜dfs
     * 首先统计需要删除的左括号和右括号的数量，
     * 然后递归遍历尝试删除每一个左括号和右括号，
     * 当需要从连续的左括号或右括号中删除一个时，我们删除第一个括号，剩余的跳过以避免重复
     */
    vector<string> res;
    vector<string> removeInvalidParentheses(string s) {
        int l = 0, r = 0;  // 统计需要删除的左括号的数量和右括号的数量
        for (auto c : s) {
            if (c == '(')
                l++;
            else if (c == ')') {
                if (l > 0)
                    l--;
                else
                    r++;
            }
        }
        dfs(s, 0, l, r);
        return res;
    }

    void dfs(string& s, int idx, int l, int r) {
        if (l == 0 && r == 0) {
            if (isValid(s)) res.push_back(s);
            return;
        }
        // 从当前位置向后遍历
        for (int i = idx; i < s.size(); i++) {
            if (i != idx && s[i] == s[i - 1]) continue;  // 去重
            if (s[i] == '(' && l > 0) {                  // 删除左括号
                string t = s;
                t.erase(i, 1);
                dfs(t, i, l - 1, r);
            }
            if (s[i] == ')' && r > 0) {  // 删除右括号
                string t = s;
                t.erase(i, 1);
                dfs(t, i, l, r - 1);
            }
        }
    }

    /**
     * 宽度优先 bfs
     * 1.删除最小括号使得字符串满足要求，那么我们怎么去删除呢，可以考虑每次给定的字符串删除一个字符有多少种可能，
     * 在这么多种可能中如果出现一例合法的，也就可以结束了.
     * 2.每次删除一个字符后的所有可能都入队列，每次处理队列数据的时候也是把当前队列中的所有元素统一处理，
     * 这样其实层次关系就出来了，在给定的层次关系下，计算计算得到最小值时的所有可能数据
     */
    vector<string> removeInvalidParentheses(string s) {
        vector<string> res;
        queue<string> q;
        unordered_set<string> hash;
        q.push(s);
        while (q.size()) {
            string t = q.front();
            q.pop();
            if (isValid(t))
                res.push_back(t);
            else if (!res.size()) {
                for (int i = 0; i < t.size(); i++) {
                    if (t[i] == '(' || t[i] == ')') {
                        string cur = t;
                        cur.erase(i, 1);
                        if (!hash.count(cur)) {
                            hash.insert(cur);
                            q.push(cur);
                        }
                    }
                }
            }
        }
        return res;
    }

    // 判断括号是否是合法的
    bool isValid(string s) {
        int cnt = 0;
        for (auto c : s) {
            if (c == '(')
                cnt++;
            else if (c == ')')
                cnt--;
            if (cnt < 0) return false;
        }
        return cnt == 0;
    }
};