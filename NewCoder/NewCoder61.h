#include <vector>

using namespace std;

#include "TreeNode.h"

/**
 * 题目61：序列化二叉树
 * 请实现两个函数，分别用来序列化和反序列化二叉树.
 *
 * 二叉树的序列化是指：把一棵二叉树按照某种遍历方式的结果以某种格式保存为字符串，
 * 从而使得内存中建立起来的二叉树可以持久保存。
 * 序列化可以基于先序、中序、后序、层序的二叉树遍历方式来进行修改，
 * 序列化的结果是一个字符串，序列化时通过
 * 某种符号表示空节点（#），以 ！ 表示一个结点值的结束（value!）。
 *
 * 二叉树的反序列化是指：根据某种遍历顺序得到的序列化字符串结果str，重构二叉树。
 */
class NewCoder61 {
   public:
    char* Serialize(TreeNode* root) {
        res.clear(); // 清除数组中的元素
        DFSSerialize(root); // 使用深度优先遍历二叉树，保存结果到数组中
        int* ser = new int[res.size()]; // 创建序列化的数组
        for (int i = 0; i < res.size(); ++i) {
            ser[i] = res[i];
        }
        // for (int i = 0; i < res.size(); i++) {
        //     cout << res[i] << "---";
        // }
        // cout << endl;
        return (char*)ser; // 使用指针强制类型转换
    }

    TreeNode* Deserialize(char* str) {
        int* pInt = (int*)str;
        return DFSDeserialize(pInt);
    }

   private:
    vector<int> res;
    void DFSSerialize(TreeNode* root) {
        if (root == nullptr) { // 结点是空时，设置标志位
            res.push_back(0x7FFFFFFF); 
        } else {
            res.push_back(root->val);
            DFSSerialize(root->left);
            DFSSerialize(root->right);
        }
    }

    /**
     * 使用深度优先反序列化来生成二叉树
     */
    TreeNode* DFSDeserialize(int*& p) {
        if (*p == 0x7FFFFFFF) {
            p++;
            return nullptr;
        }
        TreeNode* node = new TreeNode(*p);
        p++;
        node->left = DFSDeserialize(p);
        node->right = DFSDeserialize(p);
        return node;
    }
};
