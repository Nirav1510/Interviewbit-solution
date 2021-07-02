vector<int> postorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<TreeNode *> s;
    TreeNode *curr = A;
    while (true)
    {

        while (curr)
        {
            s.push(curr);
            ans.push_back(curr->val);
            curr = curr->right;
        }
        if (s.empty())
            break;

        TreeNode *temp = s.top();
        s.pop();
        curr = temp->left;
    }
    reverse(ans.begin(), ans.end());
    return ans;
}