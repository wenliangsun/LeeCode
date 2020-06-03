#include <bits/stdc++.h>

using namespace std;

/**
 * 给满出二叉树，编写算法将其转化为求和树
 * 什么是求和树：二叉树的求和树，是一颗同样结构的二叉树，其树中的每个节点将包含原始树中的左子树和右子树的和。
 *
 * 考虑题目中说的是满二叉树，所以我们只需要中序遍历的结果，而且中序遍历的长度是奇数，所以只操作中序遍历的数组即可
 */

void dfs(vector<int>& inorder, int l, int r) {
    int mid = l + r >> 1;  // 求中点
    if (mid == l) {  // 如果做结点为和中点相等，则置中点为0
        inorder[mid] = 0;
        return;
    }
    // 计算中点的值
    inorder[mid] =
        accumulate(inorder.begin() + l, inorder.begin() + r, -inorder[mid]);
    dfs(inorder, l, mid);      // 左子树
    dfs(inorder, mid + 1, r);  // 右子树
}

int main() {
    // 注意这儿的读取操作
    string line;
    getline(cin, line);
    istringstream issin(line);
    vector<int> preorder((istream_iterator<int>(issin)),
                         istream_iterator<int>());
    string line2;
    getline(cin, line2);
    istringstream issin2(line2);
    vector<int> inorder((istream_iterator<int>(issin2)),
                        istream_iterator<int>());
    dfs(inorder, 0, inorder.size());
    for (auto n : inorder) cout << n << ' ' << endl;
    return 0;
}