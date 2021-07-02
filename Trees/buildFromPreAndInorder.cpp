int search(vector<int> &in, int start, int end, int no)
{
    for (int i = start; i <= end; i++)
    {
        if (in[i] == no)
            return i;
    }
    return -1;
}

TreeNode *make(vector<int> &in, vector<int> &pre, int start, int end, int &preindex)
{

    if (start > end)
        return NULL;

    TreeNode *node = new TreeNode(pre[preindex]);
    int no = node->val;
    preindex++;

    if (start == end)
        return node;

    int pos = search(in, start, end, no);

    node->left = make(in, pre, start, pos - 1, preindex);
    node->right = make(in, pre, pos + 1, end, preindex);

    return node;
}
TreeNode *buildTree(vector<int> &pre, vector<int> &in)
{

    int k = 0;

    int n = pre.size();
    TreeNode *root = make(in, pre, 0, n - 1, k);
    return root;
}

// using map

unordered_map<int, int> m;
int idx;
TreeNode *make(vector<int> &pre, int s, int e)
{
    if (s > e)
        return NULL;

    TreeNode *root = new TreeNode(pre[idx++]);
    if (s == e)
        return root;

    root->left = make(pre, s, m[root->val] - 1);
    root->right = make(pre, m[root->val] + 1, e);
    return root;
}

TreeNode *buildTree(vector<int> &pre, vector<int> &in)
{

    m.clear();
    idx = 0;
    for (int i = 0; i < in.size(); i++)
    {
        m[in[i]] = i;
    }
    return make(pre, 0, in.size() - 1);
}