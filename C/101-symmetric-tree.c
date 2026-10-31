/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */

bool isMirror(struct TreeNode* p, struct TreeNode* q){
     if(p == NULL && q == NULL) return 1;

    if(p == NULL || q == NULL) return 0;
    
    if(p->val != q->val) return 0;

    return isMirror(p->left, q->right) && isMirror(p->right, q->left);
}

bool isSymmetric(struct TreeNode* root) {
    if(root == NULL) return 1;

    return isMirror(root->left, root->right);
}
