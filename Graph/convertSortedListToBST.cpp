TreeNode *Solution::sortedListToBST(ListNode *A)
{
    if (!A)
        return NULL;
    if (!A->next)
        return new TreeNode(A->val);
    ListNode *slow = A, *fast = A->next, *mid = NULL;

    while (fast && fast->next)
    {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    if (mid)
    {
        mid->next = NULL;
    }
    else
    {
        A = NULL;
    }

    auto root = new TreeNode(slow->val);
    root->left = sortedListToBST(A);
    root->right = sortedListToBST(slow->next);

    return root;
}