/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
struct TreeNode* sortedArrayToBST(int* nums, int numsSize) {
    if (numsSize == 0) return NULL;

    struct TreeNode *root = malloc(sizeof(struct TreeNode));

    if (root == NULL) return NULL;

    root->val = nums[numsSize / 2];
    root->left = sortedArrayToBST(nums, numsSize / 2);
    root->right = sortedArrayToBST(nums + 1 + numsSize / 2, numsSize - numsSize / 2 - 1);

    return root;
}
