int levelB;
unordered_map<int, vector<int>> m;
void traverse(TreeNode *A, int level, int B)
{
    if (A == NULL)
    {
        return;
    }
    m[level].push_back(A->val);
    TreeNode *left = A->left;
    TreeNode *right = A->right;
    if (left && left->val == B || right && right->val == B)
    {
        levelB = level + 1;
    }
    else
    {
        traverse(left, level + 1, B);
        traverse(right, level + 1, B);
    }
}
vector<int> Solution::solve(TreeNode *A, int B)
{
    m.clear();
    traverse(A, 0, B);
    return m[levelB];
}