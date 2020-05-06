#include <bits/stdc++.h>

using namespace std;

class Node {
   public:
    int val;
    Node* next;
    Node* random;
    Node(int _val) {
        val = _val;
        next = nullptr;
        random = nullptr;
    }
};

class Solution {
    unordered_map<Node*, Node*> hash;

   public:
    /**
     * 思路：先遍历一遍链表，复制所有的结点，如：A-B-C-D-nullptr 变为
     * A-A'-B-B'-C-C'-D-D'-nullptr
     * 然后根据越来链表的random指针调整复制的结点之间的random指针
     * 最后将这个链表拆分成两个链表
     * 
     * 时间复杂度：O(N)
     * 空间复杂度：O(1)
     */
    Node* copyRandomList(Node* head) {
        if (!head) return nullptr;
        Node* ptr = head;
        // 复制结点
        while (ptr != nullptr) {
            Node* newNode = new Node(ptr->val);
            newNode->next = ptr->next;
            ptr->next = newNode;
            ptr = newNode->next;
        }
        ptr = head;
        // 调整复制结点的random指针
        while (ptr != nullptr) {
            ptr->next->random = ptr->random ? ptr->random->next : nullptr;
            ptr = ptr->next->next;
        }

        Node* pOldNode = head;
        Node* pNewNode = head->next;
        Node* newHead = head->next;
        // 拆分
        while (pOldNode != nullptr) {
            pOldNode->next = pOldNode->next->next;
            pNewNode->next = pNewNode->next ? pNewNode->next->next : nullptr;
            pOldNode = pOldNode->next;
            pNewNode = pNewNode->next;
        }
        return newHead;
    }

    /**
     * 思路：从head节点开始遍历链表，首先创建一个head的拷贝，然后将新创建的节点放入字典，
     * 对于random指针，如果当前结点的random指针指向的结点已经复制过了，则直接指向复制的结点，如果没有复制过，则需要创建新的节点，然后存入字典
     * 对于next指针，如果当前结点的next指针指向的结点已经复制过了，则直接指向，否则复制结点并存入字典
     * 时间复杂度：O(N)
     * 空间复杂度：O(N)
     */
    Node* copyRandomList1(Node* head) {
        if (!head) return nullptr;
        Node* oldNode = head;
        Node* newNode = new Node(oldNode->val);
        hash[oldNode] = newNode;
        while (oldNode != nullptr) {
            newNode->random = getCloneNode(oldNode->random);
            newNode->next = getCloneNode(oldNode->next);
            oldNode = oldNode->next;
            newNode = newNode->next;
        }
        return hash[head];
    }

    Node* getCloneNode(Node* node) {
        if (node) {
            if (!hash.count(node)) hash[node] = new Node(node->val);
            return hash[node];
        } else {
            return nullptr;
        }
    }
};
