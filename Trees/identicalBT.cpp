int isSameTree(TreeNode *A, TreeNode *B)
{
    if (!A && !B)
        return 1;
    if (!A || !B)
        return 0;

    int left = isSameTree(A->left, B->left);
    int right = isSameTree(A->right, B->right);

    if (A->val != B->val)
        return 0;

    return (left && right);
}
