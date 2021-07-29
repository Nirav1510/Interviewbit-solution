vector<vector<int>> Solution::verticalOrderTraversal(TreeNode *A)
{
    vector<vector<int>> res;
    queue<pair<int, TreeNode *>> q;
    map<int, vector<int>> m;
    if (!A)
        return res;

    q.push({0, A});

    while (!q.empty())
    {
        auto p = q.front();
        q.pop();
        m[p.first].push_back(p.second->val);
        if (p.second->left)
        {
            q.push({p.first - 1, p.second->left});
        }
        if (p.second->right)
        {
            q.push({p.first + 1, p.second->right});
        }
    }
    for (auto it : m)
    {
        res.push_back(it.second);
    }
    return res;
}