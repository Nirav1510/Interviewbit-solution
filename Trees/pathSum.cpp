int hasPathSum(TreeNode *root, int targetSum)
{
    if (!root)
        return false;
    if (!root->left && !root->right)
    {
        return root->val == targetSum;
    }
    bool l = hasPathSum(root->left, targetSum - root->val);
    bool r = hasPathSum(root->right, targetSum - root->val);

    return (l || r);
}