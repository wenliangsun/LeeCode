#include <map>
#include <string>
#include <vector>

using namespace std;

/**
 * 题目30：串联所有单词的子串
 */
class LeeCode30 {
   public:
    /**
     * 思路：利用两个hashmap
     * 第一个hashmap用于保存单词表中的单词以及出现的次数
     * 第二个hashmap用于统计获取字符串中单词表长度的单词及其出现的次数。
     * 当第二个hashmap中的单词出现的次数大于第一个hasmap或者当前字符串中包含单词表中未出现的单词，则重新统计。
     * 时间复杂度：O(n*m)
     * 空间复杂度：O(m)
     */
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        if (words.empty() || s.empty()) {
            return res;
        }
        map<string, int> wordsMap;
        for (string s : words) {
            if (wordsMap.find(s) == wordsMap.end()) {
                wordsMap[s] = 1;
            } else {
                wordsMap[s]++;
            }
        }
        int wordlen = words[0].size();
        // 从前向后依次遍历字符串，注意终止边界
        for (int i = 0; i < s.size() - wordlen * words.size() + 1; i++) {
            map<string, int> hasword;  // 记录统计的单词以及出现的次数
            int nums = 0;              //记录匹配到的单词数
            // 从字符串中取出单词表个数单词
            while (nums < words.size()) {
                // 从字符串中读取一个单词
                string substr = s.substr(i + wordlen * nums, wordlen);
                // 判断该单词是否在单词表中
                if (wordsMap.find(substr) == wordsMap.end()) {
                    break;
                    // 判断是否在hashmap中
                } else if (hasword.find(substr) == hasword.end()) {
                    hasword[substr] = 1;
                } else {
                    // 判断当前hashmap中单词出现的次数是否满足单词表中单词出现的次数
                    if (hasword[substr] + 1 <= wordsMap[substr]) {
                        hasword[substr]++;
                    } else {
                        break;
                    }
                }
                nums++;
            }
            // 如果统计的单词数与单词表长度一样，说明匹配到了,记录当前开始的索引
            if (nums == words.size()) {
                res.push_back(i);
            }
        }
        return res;
    }
    /**
     * 思路：将方法一进行优化，减少判断次数
     */
    vector<int> findSubstring2(string s, vector<string>& words) {}
};