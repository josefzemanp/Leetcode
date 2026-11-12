/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
int maxDepth(struct TreeNode* root) {
    if (root == NULL) return 0;

    int left = maxDepth(root->left);
    int right = maxDepth(root->right);

    return 1 + (left > right ? left : right);
}

bool isBalanced(struct TreeNode* root) {
    if (root == NULL) return 1;
    int right = maxDepth(root->right);
    int left = maxDepth(root->left);

    int diff = (right - left) < 0 ? -(right - left) : (right - left);

    return diff <= 1 && isBalanced(root->right) && isBalanced(root->left); 
}
