bool helper(TreeNode *r1, TreeNode *r2)
{
    if (!r1 || !r2)
        return r1 == r2;

    if (r1->val != r2->val)
        return 0;

    return helper(r1->left, r2->right) && helper(r1->right, r2->left);
}

int isSymmetric(TreeNode *A)
{
    return helper(A->left, A->right);
}