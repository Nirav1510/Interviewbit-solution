//itreative
bool preOrder(TreeNode *A, vector<int> &path, int target)
{
    if (A == NULL)
    {
        return false;
    }

    path.push_back(A->val);

    if (A->val == target)
    {
        return true;
    }

    if (preOrder(A->left, path, target) || preOrder(A->right, path, target))
    {
        return true;
    }

    path.pop_back();
    return false;
}

int lca(TreeNode *A, int B, int C)
{
    vector<int> b, c;

    preOrder(A, b, B);
    preOrder(A, c, C);

    if (b.empty() || c.empty())
        return -1;

    for (int i = b.size() - 1; i >= 0; i--)
    {
        for (int j = c.size() - 1; j >= 0; j--)
        {
            if (b[j] == c[i])
                return c[j];
        }
    }
    return -1;
}

//recursive

int ans;
bool recur(TreeNode *A, int B, int C)
{
    bool flag = false;
    if (A == NULL)
    {
        return false;
    }
    else if (A->val == B && A->val == C)
    {
        ans = B;
        return true;
    }
    else if (A->val == B || A->val == C)
    {
        flag = true;
    }

    bool l = recur(A->left, B, C);
    bool r = recur(A->right, B, C);

    if (l + r + flag >= 2)
    {
        ans = A->val;
    }

    return (l || r || flag);
}

int lca(TreeNode *A, int B, int C)
{
    ans = -1;
    recur(A, B, C);
    return ans;
}