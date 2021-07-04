int res;
int solve(Node *root)
{
    if (!root)
        return 0;

    int l = solve(root->left);
    int r = solve(root->right);

    int temp = max(l, r) + 1;
    int ans = max(temp, l + r + 1);
    res = max(ans, res);
    return temp;
}

int diameter(Node *root)
{
    res = INT_MIN;
    solve(root);
    return res;
}