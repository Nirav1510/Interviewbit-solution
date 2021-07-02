vector<int> ans;
int maxlevel;
void rightView(TreeNode *root, int level)
{
    if (!root)
        return;

    if (maxlevel < level)
    {
        ans.push_back(root->val);
        maxlevel = level;
    }

    rightView(root->right, level + 1);
    rightView(root->left, level + 1);
}

vector<int> solve(TreeNode *A)
{
    ans.clear();
    maxlevel = -1;
    rightView(A, 0);
    return ans;
}