/**
 * Definition for singly-linked list.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */
RandomListNode *copyRandomList(RandomListNode *A)
{
    RandomListNode *curr = A;
    if (A == NULL)
        return A;
    unordered_map<RandomListNode *, RandomListNode *> m;

    while (curr != NULL)
    {
        m[curr] = new RandomListNode(curr->label);
        curr = curr->next;
    }

    curr = A;

    while (curr != NULL)
    {
        m[curr]->next = m[curr->next];
        m[curr]->random = m[curr->random];
        curr = curr->next;
    }
    return m[A];
}