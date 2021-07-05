vector<vector<int>> ans;

void solve(TreeNode *root, int target, vector<int> &path)
{
    if (!root)
        return;
    path.push_back(root->val);

    if (!root->left && !root->right && root->val == target)
    {
        ans.push_back(path);
    }
    target -= root->val;
    solve(root->left, target, path);
    solve(root->right, target, path);
    path.pop_back();
}

vector<vector<int>> pathSum(TreeNode *A, int B)
{
    ans.clear();
    vector<int> path;
    solve(A, B, path);
    return ans;
}