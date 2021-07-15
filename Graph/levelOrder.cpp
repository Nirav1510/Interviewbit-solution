vector<vector<int>> ans;

void solve(TreeNode *root)
{
    if (!root)
        return;

    queue<TreeNode *> q;
    q.push(root);

    while (!q.empty())
    {
        int n = q.size();
        vector<int> temp;
        while (n--)
        {
            auto t = q.front();
            q.pop();
            temp.push_back(t->val);

            if (t->left)
            {
                q.push(t->left);
            }
            if (t->right)
            {
                q.push(t->right);
            }
        }
        ans.push_back(temp);
    }
}

vector<vector<int>> Solution::levelOrder(TreeNode *A)
{
    ans.clear();
    solve(A);
    return ans;
}
