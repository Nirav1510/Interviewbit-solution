TreeNode *func(vector<int> &A, int start, int end)
{

    if (start > end)
        return NULL;

    int max = INT_MIN;
    int index;
    for (int i = start; i <= end; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
            index = i;
        }
    }

    TreeNode *temp = new TreeNode(max);
    temp->left = func(A, start, index - 1);
    temp->right = func(A, index + 1, end);

    return temp;
}
TreeNode *Solution::buildTree(vector<int> &A)
{
    int n = A.size();
    return func(A, 0, n - 1);
}