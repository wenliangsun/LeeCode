#include "ListNode.h"

/**
 * 题目142：环形链表II
 */
class LeeCode142 {
   public:
    /**
     * 思路：快慢指针法
     * 先找到快慢指针相遇的位置，此时快指针比慢指针快走了一环k，
     * 如果相遇节点距入环结点的距离是m，则头结点到入环点的距离为k-m，
     * 而相遇点到入环点的距离也是k-m，则可以把一个指针指向头结点，
     * 然后一起遍历，再次相遇的结点即为入环结点。
     */
    ListNode* detectCycle(ListNode* head) {
        ListNode* fast = head;
        ListNode* slow = head;
        while (fast != nullptr && fast->next != nullptr) {
            fast = fast->next->next;
            slow = slow->next;
            if (slow == fast) {
                break;
            }
        }
        // 排除无环的情况
        if (fast == nullptr || fast->next == nullptr) {
            return nullptr;
        }
        slow = head;
        // 再次相遇即为入环结点
        while (slow != fast) {
            slow = slow->next;
            fast = fast->next;
        }
        return slow;
    }
};