int minDepth(TreeNode *root)
{
    if (!root)
        return 0;

    int lh = minDepth(root->left);
    int rh = minDepth(root->right);
    if (lh == 0)
    {
        return rh + 1;
    }
    if (rh == 0)
    {
        return lh + 1;
    }
    return min(lh, rh) + 1;
}