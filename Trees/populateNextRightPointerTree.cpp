// O(n) space;

void Solution::connect(TreeLinkNode *A)
{
    if (!A)
        return;
    queue<TreeLinkNode *> q;
    q.push(A);

    while (!q.empty())
    {
        int n = q.size();

        while (n--)
        {
            TreeLinkNode *temp = q.front();
            q.pop();

            if (n == 0)
            {
                temp->next = NULL;
            }
            else
            {
                temp->next = q.front();
            }

            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
    }
}

// O(1) space

Node *connect(Node *head)
{
    Node *root = head;
    if (!root)
        return root;
    Node *next = root->left;

    while (root && root->left)
    {
        next = root->left;
        while (root)
        {
            root->left->next = root->right;
            if (root->next)
                root->right->next = root->next->left;

            root = root->next;
        }
        root = next;
    }
    return head;
}