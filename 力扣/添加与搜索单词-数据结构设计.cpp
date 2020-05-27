#include <bits/stdc++.h>

using namespace std;

/**
 * 题目211：添加与搜索单词
 */

class WordDictionary {
   public:
    /** Initialize your data structure here. */
    unordered_set<string> st;
    WordDictionary() {}

    /** Adds a word into the data structure. */
    void addWord(string word) { st.insert(word); }

    /** Returns if the word is in the data structure. A word could contain the
     * dot character '.' to represent any one letter. */
    bool search(string word) {
        for (auto d : st) {
            if (d.size() != word.size()) continue;
            if (d == word) return true;
            int i;
            for (i = 0; i < word.size(); i++) {
                if (d[i] != word[i] && word[i] != '.') break;
            }
            if (i == word.size()) return true;
        }
        return false;
    }
};