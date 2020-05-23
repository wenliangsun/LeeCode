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
 * 题目116：填充每个结点的下一个右侧结点指针
 */
class LeeCode116 {
   public:
    /**
     * 思路：利用层序遍历的思想
     * 每一层不是读取而是更改next的指向
     * 时间复杂度：O(N)
     * 空间复杂度：O(N) 队列
     */
    Node* connect(Node* root) {
        if (root == nullptr) {
            return root;
        }
        queue<Node*> q;
        q.push(root);
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
     * 时间复杂度：O(N)
     * 空间复杂度：O(1)
     */
    Node* connect2(Node* root) {
        if (root == nullptr) {
            return root;
        }
        Node* mostLeft = root;  // 控制数的层数
        // 为什么是->left!=nullptr，是因为根据当前层就能连接当前层的所有孩子结点
        while (mostLeft->left != nullptr) {
            Node* temp = mostLeft;
            // 横向遍历
            while (temp != nullptr) {
                // 左孩子指向右孩子
                temp->left->next = temp->right;
                // 当前结点的右孩子指向下一个结点的左孩子
                if (temp->next != nullptr) {
                    temp->right->next = temp->next->left;
                }
                temp = temp->next;  // 向右移
            }
            mostLeft = mostLeft->left;  // 向下移
        }
        return root;
    }

    /**
     * 思路：递归法
     */
    Node* connect3(Node* root) {
        if (root && root->left && root->right) {
            // 左节点指向右结点
            root->left->next = root->right;
            if (root->next) {
                // 右结点指向下一个的左节点
                root->right->next = root->next->left;
            }
            connect3(root->right);
            connect3(root->left);
        }
        return root;
    }
};