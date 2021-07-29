vector<vector<int>> zigzagLevelOrder(TreeNode *root)
{
    vector<vector<int>> ans;
    if (!root)
        return ans;
    queue<TreeNode *> q;
    q.push(root);
    int sz = 1;
    bool flag = true;
    while (!q.empty())
    {
        vector<int> temp(sz);
        for (int i = 0; i < sz; i++)
        {
            TreeNode *node = q.front();
            q.pop();
            temp[i] = node->val;
            if (node->left)
                q.push(node->left);
            if (node->right)
                q.push(node->right);
        }
        sz = q.size();
        if (flag)
        {
            ans.push_back(temp);
            flag = false;
        }
        else
        {
            reverse(temp.begin(), temp.end());
            ans.push_back(temp);
            flag = true;
        }
    }
    return ans;
}