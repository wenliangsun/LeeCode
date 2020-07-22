#include <bits/stdc++.h>

using namespace std;

/**
 * 实现Trie前缀树
 */

class Trie {
public:
    /** Initialize your data structure here. */
    struct Node {
        bool is_end;
        Node* son[26];
        Node() {
            is_end = false;
            for (int i = 0 ; i < 26; i++) son[i] = nullptr;
        }
    }*root;
    
    Trie() {
        root = new Node();
    }
    
    /** Inserts a word into the trie. */
    void insert(string word) {
        auto p = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (!p->son[idx]) p->son[idx] = new Node();
            p = p->son[idx];
        }
        p->is_end = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string word) {
        auto p = root;
        for (auto c : word) {
            int idx = c - 'a';
            if (!p->son[idx]) return false;
            p = p->son[idx];
        }
        return p->is_end;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string prefix) {
        auto p = root;
        for (auto c : prefix) {
            int idx = c - 'a';
            if (!p->son[idx]) return false;
            p = p->son[idx];
        }
        return true;
    }
};