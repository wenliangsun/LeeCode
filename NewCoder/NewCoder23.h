//
// Created by wenliangsun on 2020/2/10.
//

#ifndef C__ALGORITHM_NEWCODER23_H
#define C__ALGORITHM_NEWCODER23_H

#include <vector>

#endif //C__ALGORITHM_NEWCODER23_H
using std::vector;

/**
 * 题目23：二叉树的后序遍历序列
 * 输入一个整数数组，判断该数组是不是某二叉搜索树的后序遍历结果，如果是则输出yes，否则No。
 * 假设输入的数组的任意两个数字相互不同。
 */
class NewCoder23 {
public:
    bool VerifySquenceOfBST(vector<int> sequence) {
        return bst(sequence, 0, sequence.size() - 1);
    }

    /**
     * 思路：二叉搜索树的左子树都小于根节点，右子树都大于根节点，使用递归方法
     */
    bool bst(vector<int> seq, int start, int end) {
        if (seq.empty() || end < start)
            return false;
        int root = seq[end];
        int index = start;
        for (; index < end; ++index) { // 寻找左子树结束位置
            if (seq[index] > root)
                break;
        }
        for (int i = index; i < end; ++i) { // 判断右子树是否全都大于根节点
            if (seq[i] < root)
                return false;
        }
        bool left = true;
        if (index > start) { // 递归左子树
            left = bst(seq, start, index - 1);
        }
        bool right = true;
        if (index < end) { // 递归右子树
            right = bst(seq, index, end - 1);
        }
        return left && right;
    }
};