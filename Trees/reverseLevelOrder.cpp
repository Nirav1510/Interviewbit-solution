void Solve(TreeNode *root, vector<int> &ans)
{
    if (root == NULL)
        return;
    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        for (int i = 0; i < n; i++)
        {
            TreeNode *curr = q.front();
            ans.push_back(curr->val);
            q.pop();

            if (curr->right)
            {
                q.push(curr->right);
            }
            if (curr->left)
            {
                q.push(curr->left);
            }
        }
    }
}

vector<int> solve(TreeNode *A)
{
    vector<int> ans;
    TreeNode *root = A;
    Solve(root, ans);
    reverse(ans.begin(), ans.end());
    return ans;
}