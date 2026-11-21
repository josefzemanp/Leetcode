int* preorderTraversal(struct TreeNode* root, int* returnSize) {
    *returnSize = 0;

    if (root == NULL) return NULL;

    size_t capacity = 5;
    struct TreeNode** stack = malloc(capacity * sizeof(*stack));
    int* res = malloc(100 * sizeof(*res));

    if (stack == NULL || res == NULL) {
        free(stack);
        free(res);
        return NULL;
    }

    size_t top = 0;
    stack[top++] = root;

    while (top > 0) {
        struct TreeNode* node = stack[--top];

        res[(*returnSize)++] = node->val;

        if (top + 2 > capacity) {
            capacity *= 2;

            struct TreeNode** tmp = realloc(stack, capacity * sizeof(*stack));

            if (tmp == NULL) {
                free(stack);
                free(res);
                *returnSize = 0;
                return NULL;
            }

            stack = tmp;
        }

        if (node->right != NULL) stack[top++] = node->right;

        if (node->left != NULL) stack[top++] = node->left;
    }

    free(stack);
    return res;
}
