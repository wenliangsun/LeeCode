#include <bits/stdc++.h>

using namespace std;

/**
 * 题目：婴儿名字
 */

class Solution {
   public:
    vector<int> p;  // 根节点集合
    typedef pair<string, int> PII;
    vector<string> trulyMostPopular(vector<string>& names,
                                    vector<string>& synonyms) {
        int n = names.size();
        p = vector<int>(n);
        for (int i = 0; i < n; i++) p[i] = i;  // 初始化
        vector<PII> nms(n); // 用于存储名字和次数
        unordered_map<string, int> hash; // 名字和索引对应
        for (int i = 0; i < n; i++) {
            int pos = names[i].find('(');
            nms[i] = {
                names[i].substr(0, pos),
                stoi(names[i].substr(pos + 1, names[i].size() - pos - 2))};
            hash[names[i].substr(0, pos)] = i;
        }
        for (auto item : synonyms) {
            int pos = item.find(',');
            string n1 = item.substr(1, pos - 1);
            string n2 = item.substr(pos + 1, item.size() - pos - 2);
            p[find(hash[n1])] = find(hash[n2]); // 合并
        }
        vector<string> res;
        map<string, int> cnt; // 用于统计合并后名字出现的次数
        map<string, vector<string>> tmp; // 用于记录名字集合
        for (int i = 0; i < n; i++) {
            int root = find(i);
            tmp[nms[root].first].push_back(nms[i].first); // 把具有相同根节点的名字保存，以便后续获得这些名字中字典序最小的一个输出
            cnt[nms[root].first] += nms[i].second; // 计数
        }
        for (auto item : cnt) {
            sort(tmp[item.first].begin(), tmp[item.first].end()); // 对当前名字集合进行排序
            res.push_back(tmp[item.first][0] + "(" + to_string(item.second) + ")");
        }

        return res;
    }

    int find(int x) {
        if (x == p[x]) return x;
        p[x] = find(p[x]);
        return p[x];
    }
};