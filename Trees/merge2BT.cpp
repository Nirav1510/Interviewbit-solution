TreeNode *mergeTrees(TreeNode *root1, TreeNode *root2)
{
    if (!root1 && !root2)
        return NULL;
    if (!root1)
        return root2;
    if (!root2)
        return root1;

    TreeNode *ans = new TreeNode(root1->val + root2->val);
    ans->left = mergeTrees(root1->left, root2->left);
    ans->right = mergeTrees(root1->right, root2->right);

    return ans;
}