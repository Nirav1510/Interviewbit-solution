ListNode* reverseBetween(ListNode* A, int m, int n) {
    ListNode* dummy = new ListNode(-1);
    dummy->next=A;
    ListNode* prev=dummy;
    ListNode* curr=A;
    
    for(int i=0;i<m-1;i++){
        prev=prev->next;
        curr=curr->next;
    }
    while(m++<n){
        ListNode* temp=curr->next;
        curr->next=temp->next;
        temp->next=prev->next;
        prev->next=temp;
    }
    return dummy->next;
}