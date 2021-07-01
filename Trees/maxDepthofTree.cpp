struct TreeNode
{
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

int maxDepth(TreeNode *A)
{
    if (A == NULL)
        return 0;

    int ls = maxDepth(A->left);
    int rs = maxDepth(A->right);

    return max(ls, rs) + 1;
}