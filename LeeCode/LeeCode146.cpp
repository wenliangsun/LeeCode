#include <iostream>
#include <list>
#include <unordered_map>

using namespace std;

/**
 * 题目146：LRU缓存机制
 */
class LRUCache {
   public:
    LRUCache(int capacity) { this->cap = capacity; }

    int get(int key) {
        // 如果包含键，则将该键放在链表头
        if (m.count(key)) {
            pair<int, int> temp = *m[key];
            cache.erase(m[key]);
            cache.push_front(temp);
            m[key] = cache.begin();
            return temp.second;
        } else {
            return -1;
        }
    }

    void put(int key, int value) {
        // 如果包含键，更新键值，并放在链表头
        if (m.count(key)) {
            cache.erase(m[key]);
            cache.push_front(make_pair(key, value));
            m[key] = cache.begin();
        } else {
            // 否则判断是否超出容量，如果超出，删除链表尾的一个结点，并将新节点放在链表头
            if (cache.size() == cap) {
                auto lastpair = cache.back();
                int lastkey = lastpair.first;
                m.erase(lastkey);
                cache.pop_back();
            }
            cache.push_front(make_pair(key, value));
            m[key] = cache.begin();
        }
    }

   private:
    int cap;  // cache 容量
    // 哈希表，key 映射到(key value)在cache中的位置 这儿不太懂
    unordered_map<int, list<pair<int, int>>::iterator> m;
    // 双向链表，装着key value 元组
    list<pair<int, int>> cache;
};