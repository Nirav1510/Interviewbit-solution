int solve(TreeNode *A)
{
    int ans = INT_MIN;
    if (!A)
        return 0;
    queue<TreeNode *> q;
    q.push(A);
    while (!q.empty())
    {
        int sum = 0, n = q.size();

        for (int i = 0; i < n; i++)
        {
            TreeNode *temp = q.front();
            sum += temp->val;
            q.pop();

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
        ans = max(ans, sum);
    }
    return ans;
}

//using map+recursion

map<int, int> mp;

void dfs(TreeNode *A, int dep)
{
    if (A == NULL)
        return;
    mp[dep] += A->val;
    dfs(A->left, dep + 1);
    dfs(A->right, dep + 1);
}

int solve(TreeNode *A)
{
    mp.clear();
    dfs(A, 0);
    int mx = A->val;
    for (auto it = mp.begin(); it != mp.end(); it++)
    {
        mx = max(mx, it->second);
    }
    return mx;
}
