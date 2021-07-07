void inOrder(TreeNode *root, vector<int> &in)
{
    if (!root)
        return;
    inOrder(root->left, in);
    in.push_back(root->val);
    inOrder(root->right, in);
}

int Solution::kthsmallest(TreeNode *root, int k)
{
    vector<int> in;
    inOrder(root, in);
    if (k > in.size())
    {
        return -1;
    }
    return in[k - 1];
}