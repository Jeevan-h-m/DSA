/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* build(int* preorder, int ps, int pe,  int* inorder, int is, int ie) {
    if (ps > pe || is > ie)
        return NULL;

    struct TreeNode* root =
        (struct TreeNode*)malloc(sizeof(struct TreeNode));
    root->val = preorder[ps];
    root->left = root->right = NULL;

    int idx = is;
    while (inorder[idx] != preorder[ps])
        idx++;

    int leftSize = idx - is;

    root->left = build(preorder, ps + 1, ps + leftSize, inorder, is, idx - 1);
    root->right = build(preorder, ps + leftSize + 1, pe, inorder, idx + 1, ie);

    return root;
}

struct TreeNode* buildTree(int* preorder, int preorderSize, int* inorder, int inorderSize) {
    return build(preorder, 0, preorderSize - 1, inorder, 0, inorderSize - 1);
}
