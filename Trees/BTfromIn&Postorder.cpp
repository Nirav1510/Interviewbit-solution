unordered_map<int, int> m;
int idx;

TreeNode *make(vector<int> &post, int s, int e)
{
    if (s > e)
        return NULL;

    TreeNode *root = new TreeNode(post[idx--]);

    if (s == e)
        return root;

    root->right = make(post, m[root->val] + 1, e);
    root->left = make(post, s, m[root->val] - 1);

    return root;
}

TreeNode *Solution::buildTree(vector<int> &in, vector<int> &post)
{
    m.clear();
    idx = in.size() - 1;

    for (int i = 0; i < in.size(); i++)
    {
        m[in[i]] = i;
    }
    return make(post, 0, in.size() - 1);
}