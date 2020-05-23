#include <bits/stdc++.h>

using namespace std;

/**
 * 题目380：常数时间插入删除获取随机元素
 */

class RandomizedSet {
    vector<int> data;
    unordered_map<int, int> hash;

   public:
    /** Initialize your data structure here. */
    RandomizedSet() {}

    /** Inserts a value to the set. Returns true if the set did not already
     * contain the specified element. */
    bool insert(int val) {
        if (!hash.count(val)) {
            data.push_back(val);
            hash[val] = data.size() - 1;
            return true;
        }
        return false;
    }

    /** Removes a value from the set. Returns true if the set contained the
     * specified element. */
    bool remove(int val) {
        if (hash.count(val)) {
            int tIdx = hash[val];
            hash[data.back()] = tIdx;
            data[tIdx] = data.back();
            data.resize(data.size() - 1);
            hash.erase(val);
            return true;
        }
        return false;
    }

    /** Get a random element from the set. */
    int getRandom() {
        if (data.empty()) return -1;
        int idx = rand() % data.size();
        return data[idx];
    }
};