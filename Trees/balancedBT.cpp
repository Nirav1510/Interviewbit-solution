int height(TreeNode *root)
{
    if (!root)
        return 0;

    return max(height(root->left), height(root->right)) + 1;
}

int isBalanced(TreeNode *A)
{
    if (!A)
        return 1;
    if (!isBalanced(A->left) || !isBalanced(A->right))
        return 0;

    return abs(height(A->left) - height(A->right)) <= 1 ? 1 : 0;
}
