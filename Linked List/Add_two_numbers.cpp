ListNode* addTwoNumbers(ListNode* A, ListNode* B) {
    if(!A) return B;
    if(!B) return A;
    ListNode* dummy=new ListNode(0);
    ListNode* curr=dummy;
    int carry=0;
    int sum=0;
    while(A || B || carry){
        sum = (A?A->val:0)+(B?B->val:0)+carry;
        carry=sum/10;
        A=A?A->next:NULL;
        B=B?B->next:NULL;
        curr->next=new ListNode(sum%10);
        curr=curr->next;
    }
    return dummy->next;
}