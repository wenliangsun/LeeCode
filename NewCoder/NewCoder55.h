#include <map>
#include "ListNode.h"

using namespace std;

/**
 * 题目55：链表中环的入口结点
 * 给一个链表，若其中包含环，请找出该链表的环的入口结点，否则，输出null。
 */
class NewCoder55 {
   public:
    ListNode* EntryNodeOfLoop01(ListNode* pHead) {
        if (pHead == nullptr) {
            return nullptr;
        }
        map<ListNode*, int> m;
        while (pHead != nullptr) {
            if (m.find(pHead) != m.end()) {
                m[pHead]++;
                if (m[pHead] == 2) {
                    return pHead;
                }
            } else {
                m[pHead] = 1;
            }
            pHead = pHead->next;
        }
        return nullptr;
    }

    ListNode* EntryNodeOfLoop02(ListNode* pHead) {
        
    }
};