vector<int> ans;

void helper(TreeNode *root, int &B, vector<int> &op)
{
    if (!root)
        return;

    op.push_back(root->val);

    if (root->val == B)
    {
        ans = op;
        return;
    }
    helper(root->left, B, op);
    helper(root->right, B, op);
    op.pop_back();
}

vector<int> solve(TreeNode *A, int B)
{
    ans.clear();
    vector<int> op;
    helper(A, B, op);
    return ans;
}