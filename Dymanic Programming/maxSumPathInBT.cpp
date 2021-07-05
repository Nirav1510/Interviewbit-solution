int res;

int solve(TreeNode *A)
{
    if (!A)
        return 0;
    int l = solve(A->left);
    int r = solve(A->right);
    int temp = max(A->val, A->val + max(l, r));
    int ans = max(temp, l + r + A->val);
    res = max(res, ans);
    return temp;
}

int maxPathSum(TreeNode *A)
{
    res = INT_MIN;
    solve(A);
    return res;
}