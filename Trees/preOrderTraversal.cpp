vector<int> preorderTraversal(TreeNode *A)
{

    vector<int> ans;
    stack<TreeNode *> s;
    while (true)
    {

        while (A != NULL)
        {

            ans.push_back(A->val);
            s.push(A);
            A = A->left;
        }

        if (s.empty())
        {
            break;
        }

        A = s.top();
        s.pop();
        A = A->right;
    }
    return ans;
}

//recursion

void solve(TreeNode *root, vector<int> &ans)
{
    if (!root)
        return;

    ans.push_back(root->val);
    solve(root->left, ans);
    solve(root->right, ans);
}

vector<int> preorderTraversal(TreeNode *A)
{
    vector<int> ans;
    solve(A, ans);
    return ans;
}