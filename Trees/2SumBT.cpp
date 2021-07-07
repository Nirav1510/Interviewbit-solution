vector<int> v;

void inOrder(TreeNode *root)
{
    if (!root)
        return;

    inOrder(root->left);
    v.push_back(root->val);
    inOrder(root->right);
}

int t2Sum(TreeNode *A, int k)
{
    v.clear();
    inOrder(A);
    int i = 0, j = v.size() - 1;
    while (i < j)
    {
        int sum = v[i] + v[j];

        if (sum == k)
            return 1;

        else if (sum > k)
            j--;
        else
            i++;
    }
    return 0;
}