struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x)
        : val(x), left(nullptr), right(nullptr), next(nullptr) {}
};