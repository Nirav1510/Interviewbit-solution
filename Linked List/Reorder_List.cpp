/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
ListNode* middleList(ListNode *A){
    ListNode* slow=A ,*fast=A;
    while(fast->next && fast->next->next){
        slow=slow->next;
        fast=fast->next->next;
    }
    fast=slow->next;
    slow->next=NULL;
    return fast;
}

ListNode* reverse(ListNode* A){
    ListNode* prev=NULL,*curr=A,*nextp;
    while(curr){
        nextp=curr->next;
        curr->next=prev;
        prev=curr;
        curr=nextp;
    }
    return prev;
}

ListNode* merge(ListNode* l1, ListNode* l2){
    ListNode *A=l1,*prev=l1;
    l1=l1->next;
    while(l1 && l2){
        prev->next=l2;
        l2=l2->next;
        prev=prev->next;
        
        prev->next=l1;
        l1=l1->next;
        prev=prev->next;
    }
    if(l1) prev->next=l1;
    if(l2) prev->next=l2;
    return A;
}

ListNode* reorderList(ListNode* A) {
    ListNode* req = middleList(A);
    req=reverse(req);
    ListNode* ans = merge(A,req);
    return ans;
}
