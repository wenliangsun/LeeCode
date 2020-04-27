#include <algorithm>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

using namespace std;

/**
 * 题目49：字母异位词分组
 */
class LeeCode49 {
   public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string, vector<string>> hash;
        for (auto str : strs) {
            string key = str;
            sort(key.begin(), key.end());
            hash[key].push_back(str);
        }
        vector<vector<string>> res;
        for (auto item : hash) res.push_back(item.second);
        return res;
    }

    vector<vector<string>> groupAnagrams2(vector<string>& strs) {
        vector<vector<string>> res;
        if (strs.empty()) {
            return res;
        }
        int index = 0;  // 答案数组的索引
        // 键是排序的字符串，值表示排序相等的字符串在答案数组中的索引。
        map<string, int> m;
        for (string str : strs) {
            string temp = str;
            // 对字符串排序
            sort(temp.begin(), temp.end());
            // 如果该排序的字符串对应的数组已经存在，则添加到相应的数组中去
            if (m.count(temp)) {
                res[m[temp]].push_back(str);
                // 否则创建一个新的数组，添加进去
            } else {
                vector<string> vec{str};
                res.push_back(vec);
                m[temp] = index++;
            }
        }
        return res;
    }
};