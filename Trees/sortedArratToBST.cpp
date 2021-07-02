TreeNode *build(const vector<int> &A, int s, int e)
{
    if (s > e)
        return NULL;

    int mid = s + (e - s) / 2;

    TreeNode *root = new TreeNode(A[mid]);

    root->left = build(A, s, mid - 1);
    root->right = build(A, mid + 1, e);

    return root;
}

TreeNode *sortedArrayToBST(const vector<int> &A)
{
    if (A.size() == 0)
        return NULL;
    return build(A, 0, A.size() - 1);
}