ListNode *mergeSort(ListNode *a, ListNode *b)
{
    ListNode *dummy = new ListNode(-1);
    ListNode *temp = dummy;
    ListNode *t1 = a, *t2 = b;

    while (t1 && t2)
    {
        if (t1->val < t2->val)
        {
            temp->next = t1;
            temp = temp->next;
            t1 = t1->next;
        }
        else
        {
            temp->next = t2;
            temp = temp->next;
            t2 = t2->next;
        }
    }
    while (t1)
    {
        temp->next = t1;
        temp = temp->next;
        t1 = t1->next;
    }
    while (t2)
    {
        temp->next = t2;
        temp = temp->next;
        t2 = t2->next;
    }
    return dummy->next;
}

ListNode *mergeSortRecursive(ListNode *a, ListNode *b)
{
    if (a == NULL)
        return b;
    if (b == NULL)
        return a;

    ListNode *ans;

    if (a->val < b->val)
    {
        ans = a;
        ans->next = mergeSortRecursive(a->next, b);
    }
    else
    {
        ans = b;
        ans->next = mergeSortRecursive(a, b->next);
    }
    return ans;
}

ListNode *Solution::sortList(ListNode *head)
{
    if (head->next == NULL || head == NULL)
        return head;
    ListNode *slow = head, *fast = head, *mid = head;
    while (fast && fast->next)
    {
        mid = slow;
        slow = slow->next;
        fast = fast->next->next;
    }

    mid->next = NULL;

    ListNode *left = sortList(head);
    ListNode *right = sortList(slow);

    return mergeSort(left, right);
}
