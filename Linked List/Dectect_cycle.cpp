ListNode* Solution::detectCycle(ListNode* A) {
    
    bool flag=false;
    ListNode* slow=A;
    ListNode* fast=A;
    while(fast!=NULL && fast->next!=NULL){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast){
            flag=true;
            break;
        }
    }
    if(flag){
        slow=A;
        while(slow!=fast){
            slow=slow->next;
            fast=fast->next;
        }
        return slow;
    }
    return NULL;
}