//space = O(n)

ListNode *Solution::partition(ListNode *head, int x)
{
    queue<int> small, large;
    ListNode *temp = head;

    while (temp)
    {
        if (temp->val < x)
        {
            small.push(temp->val);
        }
        else
        {
            large.push(temp->val);
        }
        temp = temp->next;
    }
    temp = head;
    while (!small.empty())
    {
        temp->val = small.front();
        small.pop();
        temp = temp->next;
    }
    while (!large.empty())
    {
        temp->val = large.front();
        large.pop();
        temp = temp->next;
    }
    return head;
}

//space O(1)

ListNode *Solution::partition(ListNode *head, int x)
{

    ListNode *left = new ListNode(-1);
    ListNode *right = new ListNode(-1);
    ListNode *l = left, *r = right;

    while (head)
    {
        if (head->val < x)
        {
            l->next = head;
            l = l->next;
        }
        else
        {
            r->next = head;
            r = r->next;
        }
        head = head->next;
    }

    l->next = right->next;
    r->next = NULL;

    return left->next;
}