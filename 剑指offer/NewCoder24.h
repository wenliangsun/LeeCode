//
// Created by wenliangsun on 2020/2/10.
//

#ifndef C__ALGORITHM_NEWCODER24_H
#define C__ALGORITHM_NEWCODER24_H

#include <vector>
#include "TreeNode.h"

#endif //C__ALGORITHM_NEWCODER24_H
using std::vector;

/**
 * 题目：二叉树中和为某一值的路径
 * 输入一颗二叉树的跟节点和一个整数，打印出二叉树中结点值的和为输入整数的所有路径。
 * 路径定义为从树的根结点开始往下一直到叶结点所经过的结点形成一条路径。
 * (注意: 在返回值的list中，数组长度大的数组靠前)
 */
class NewCoder24 {
    /**
     * 思路：先序遍历二叉树。
     * 使用一个变量来累计访问当前路径的和，
     * 当访问当前结点时，判断当前累计和是不是等于期望的值，
     * 若是且当前结点是叶子节点，则将该路径添加到有效路径中，
     * 若不是叶子结点，则将该路径添加到当前路径，遍历左子树和右子树。
     * @param root
     * @param expectNumber
     * @return
     */
    vector<vector<int >> res;
    vector<int> curPath;

    vector<vector<int> > FindPath(TreeNode *root, int expectNumber) {
        if (root == NULL)
            return res;
        int currentSum = 0;
        Find(root, res, curPath, currentSum, expectNumber);
        // 对路径数组按照路径长度排序。
        for (int i = 0; i < res.size(); ++i) {
            bool flag = true;
            for (int j = 0; j < res.size()-1- i; ++j) {
                if (res[j].size() < res[j+1].size()){
                    vector<int> temp = res[j];
                    res[j] = res[j+1];
                    res[j+1] = temp;
                    flag = false;
                }
            }
            if (flag)
                break;
        }
        return res;
    }

    void Find(TreeNode *root, vector<vector<int>> &res, vector<int> &curPath, int currentSum, int expectNumber) {
        if (root == NULL)
            return;
        currentSum += root->val;
        if (root->left == NULL && root->right == NULL) { // 首先判断是否是叶子结点，不能根据expectSum来判断，因为结点中的值有可能为负数。
            if (currentSum == expectNumber) {
                curPath.push_back(root->val);
                res.push_back(curPath);
                curPath.pop_back();
            }
            return; // 如果是叶子结点，但不是有效的路径，则直接返回。
        }
        curPath.push_back(root->val);
        Find(root->left, res, curPath, currentSum, expectNumber);
        Find(root->right, res, curPath, currentSum, expectNumber);
        curPath.pop_back();
    }

    /**
     * 不用定义累计和，使用expectSum-当前结点的值是否等于0来判断
     * @param root
     * @param sum
     */
    void Find2(TreeNode *root, int sum) {
        if (root == NULL)
            return;
        curPath.push_back(root->val);
        if (root->left == NULL && root->right == NULL) { // 首先判断是否是叶子结点！！！
            if (sum - root->val == 0) {
                res.push_back(curPath);
            }
        } else {
            Find2(root->left, sum - root->val);
            Find2(root->right, sum - root->val);
        }
        curPath.pop_back();
    }
};
