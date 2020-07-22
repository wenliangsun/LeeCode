#include <bits/stdc++.h>

using namespace std;

/**
 * LRU缓存机制
 */

class LRUCache {
public:
    typedef pair<int, int> PII;
    unordered_map<int, list<PII>::iterator> m; // 哈希表
    list<PII> cache; // 双向链表
    int cap = 0;

    LRUCache(int capacity) {
        cap = capacity;
    }
    
    int get(int key) {
        if (m.count(key)) {
            auto t = *m[key]; // 找到双向链表中的结点
            cache.erase(m[key]); // 先删除该节点
            cache.push_front(t);  // 再把节点放在链表头
            m[key] = cache.begin(); // 把哈希表中的值更新为链接头
            return t.second;
        } else return -1;
    }
    
    void put(int key, int value) {
        if (m.count(key)) { // 如果包含键，则直接删除链表结点
            cache.erase(m[key]);
        } else {
            if (cache.size() == cap) {
                auto last = cache.back(); // 记录最后一个结点的值
                cache.pop_back(); // 删除最后一个结点
                m.erase(last.first); // 删除最后一个结点在哈希表中的键
            }
        }
        cache.push_front({key, value});
        m[key] = cache.begin();
    }
};