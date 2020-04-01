#include <queue>

using namespace std;

class Node {
   public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val) : val(_val), left(nullptr), right(nullptr), next(nullptr) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};

/**
 * 题目117：填充每个结点的下一个右侧结点指针II
 */
class LeeCode117 {
   public:
    /**
     * 思路：使用队列，方法和LeeCode116一样
     * 时间复杂度：O(N)
     * 空间复杂度：O(N) 队列
     */
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> q;
        while (!q.empty()) {
            int len = q.size();
            Node* pre = q.front();
            if (pre->left) {
                q.push(pre->left);
            }
            if (pre->right) {
                q.push(pre->right);
            }
            q.pop();
            for (int i = 0; i < len - 1; i++) {
                Node* temp = q.front();
                pre->next = temp;
                pre = temp;
                if (temp->left) {
                    q.push(temp->left);
                }
                if (temp->right) {
                    q.push(temp->right);
                }
                q.pop();
            }
        }
        return root;
    }

    /**
     * 思路：利用已有的next指针
     * 有错误！！！
     */
    Node* connect2(Node* root) {
        if (root == nullptr) {
            return root;
        }
        Node* mostLeft = root;
        while (mostLeft->left != nullptr) {
            Node* temp = mostLeft;
            Node* pre = nullptr;

            while (temp != nullptr) {
                if (temp->left && temp->right) {
                    temp->left->next = temp->right;
                }
                pre = temp->right ? temp->right : temp->left;

                if (temp->next != nullptr) {
                    if (pre && temp->next->left) {
                        pre->next = temp->next->left;
                    } else if (pre && temp->next->right) {
                        pre->next = temp->next->right;
                    }
                    pre = pre ? (temp->left ? temp->left : temp->right)
                }
                temp = temp->next;
            }
            while (mostLeft->left == nullptr && mostLeft->right == nullptr) {
                mostLeft = mostLeft->next;
            }
            if (mostLeft == nullptr) {
                break;
            }
            if (mostLeft->left == nullptr) {
                mostLeft = mostLeft->right;
            }
            mostLeft = mostLeft->left;
        }
        return root;
    }

    /**
     * 思路：递归法
     * 对于任意依次递归，只考虑如何设置子节点的next属性，分三种情况：
     *  (1)没有子结点，直接返回
     *  (2)如果有一个子节点：将这个子节点的next属性设置为同层的下一个结点，成root->next的最左边的一个结点
     *  (3)有两个结点，左节点指向右结点，然后右结点和(2)一样的操作
     */
    Node* connect3(Node* root) {
        // 排除没有子节点的情况
        if (root && (root->left || root->right)) {
            //既有做子节点又有右子节点，左节点指向右结点
            if (root->left && root->right) {
                root->left->next = root->right;
            }
            // 获得当前结点的最右侧的结点
            Node* node = root->right ? root->right : root->left;
            // 当前结点的同层的下一个结点
            Node* head = root->next;
            // 排除没有子节点的结点
            while (head && (head->left == nullptr && head->right == nullptr)) {
                head = head->next;
            }
            // 将当前结点最右边的结点的next指向下一个结点的最左边的结点
            node->next =
                head ? (head->left ? head->left : head->right) : nullptr;
            connect3(root->right);
            connect3(root->left);
        }
        return root;
    }
};