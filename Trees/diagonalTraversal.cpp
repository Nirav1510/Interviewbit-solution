// TC = O(n) space = O(n)
vector<int> Solution::solve(TreeNode *A)
{
    vector<int> ans;
    if (!A)
        return ans;
    queue<TreeNode *> q;
    q.push(A);

    while (!q.empty())
    {
        int n = q.size();
        while (n--)
        {
            TreeNode *temp = q.front();
            q.pop();

            while (temp != NULL)
            {
                ans.push_back(temp->val);
                if (temp->left)
                {
                    q.push(temp->left);
                }
                temp = temp->right;
            }
        }
    }
    return ans;
}

//or

void build(TreeNode *A, int i, map<int, vector<int>> &um)
{
    if (A == NULL)
        return;

    um[i].push_back(A->val);

    build(A->left, i + 1, um);
    build(A->right, i, um);
}

vector<int> Solution::solve(TreeNode *A)
{
    map<int, vector<int>> um;
    vector<int> v;
    build(A, 0, um);
    auto it = um.begin();
    while (it != um.end())
    {
        vector<int> temp = it->second;
        for (int i = 0; i < temp.size(); i++)
            v.push_back(temp[i]);
        it++;
    }

    return v;
}