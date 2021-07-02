TreeNode *invertTree(TreeNode *A)
{
    if (!A)
        return NULL;

    TreeNode *r = invertTree(A->right);
    TreeNode *l = invertTree(A->left);

    A->left = r;
    A->right = l;

    return A;
}

//Iterative Solution

TreeNode *invertTree(TreeNode *root)
{
    if (root == NULL)
        return NULL;
    queue<TreeNode *> q;
    q.push(root);
    while (!q.empty())
    {
        TreeNode *curr = q.front();
        q.pop();
        swap(curr->left, curr->right);
        if (curr->left)
            q.push(curr->left);
        if (curr->right)
            q.push(curr->right);
    }
    return root;
}