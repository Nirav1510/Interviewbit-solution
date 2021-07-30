TreeNode *Solution::solve(TreeNode *A)
{
    if (!A)
        return NULL;

    if (!A->left && !A->right)
        return A;

    if (!A->left || !A->right)
    {
        TreeNode *temp;

        if (A->left)
        {
            temp = A->left;
        }
        else if (A->right)
        {
            temp = A->right;
        }

        delete A;

        return solve(temp);
    }
    A->left = solve(A->left);
    A->right = solve(A->right);
    return A;
}