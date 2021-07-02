vector<int> inorderTraversal(TreeNode *A)
{
    vector<int> ans;
    stack<TreeNode *> s;
    if (!A)
        return ans;

    TreeNode *curr = A;
    curr = A->left;
    s.push(A);
    while (!s.empty() || curr)
    {

        while (curr)
        {
            s.push(curr);
            curr = curr->left;
        }

        TreeNode *temp = s.top();
        s.pop();
        ans.push_back(temp->val);
        curr = temp->right;
    }
    return ans;
}

//Recursive

void inorder(TreeNode *root, vector<int> &vec)
{
    if (!root)
        return;

    inorder(root->left, vec);
    vec.push_back(root->val);
    inorder(root->right, vec);
}

vector<int> inorderTraversal(TreeNode *A)
{
    vector<int> v;
    inorder(A, v);
    return v;
}

// map

vector<int> inorderTraversal(TreeNode *A)
{

    vector<int> ans;

    unordered_map<TreeNode *, int> mp;

    stack<TreeNode *> s;

    s.push(A);

    while (!s.empty())
    {
        TreeNode *curr = s.top();

        if (curr == NULL)
        {
            s.pop();
            continue;
        }

        if (mp[curr] == 0)
            s.push(curr->left);
        else if (mp[curr] == 1)
            ans.push_back(curr->val);
        else if (mp[curr] == 2)
            s.push(curr->right);
        else
            s.pop();

        mp[curr]++;
    }

    return ans;
}