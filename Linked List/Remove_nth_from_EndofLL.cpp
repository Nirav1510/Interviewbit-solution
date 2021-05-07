// CPP program to delete nth node from last
#include <bits/stdc++.h>
using namespace std;

// Structure of node
struct Node {
	int data;
	struct Node* next;
};

// Function to insert node in a linked list
struct Node* create(struct Node* head, int x)
{
	struct Node *temp, *ptr = head;
	temp = new Node();
	temp->data = x;
	temp->next = NULL;
	if (head == NULL)
		head = temp;
	else {
		while (ptr->next != NULL) {
			ptr = ptr->next;
		}
		ptr->next = temp;
	}
	return head;
}

// Function to remove nth node from last
int length(Node *head){
    int count=0;
    while(head!=NULL){
        head=head->next;
        count++;
    }
    return count;
}
Node* removeNthFromEnd(Node* A, int B) {
    int l=length(A);
    if(B>=l){
        A=A->next;
        return A;
    }
    if(B==1){
        Node* res=A;
        if(A->next==NULL) return nullptr;
        while(A->next->next!=NULL){
            A=A->next;
        }
        A->next=NULL;
        return res;
    }
    int t=l-B;
    int c=1;
    Node* ans=A;
    while(A!=NULL && A->next!=NULL && c<t){
        A=A->next;
        c++;
    }
    Node* todelete=A->next;
    A->next=A->next->next;
    delete(todelete);
    return ans;
}
// This function prints contents of linked
// list starting from the given node
void dispaly(struct Node* head)
{

	struct Node* temp = head;
	while (temp != NULL) {
		cout << temp->data << " ";
		temp = temp->next;
	}
	cout << endl;
}

// Driver code
int main()
{
	struct Node* head = NULL;
	
	
	head = create(head, 1);
	head = create(head, 2);
	head = create(head, 3);
	head = create(head, 4);
	head = create(head, 5);
    head = create(head, 6);
    head = create(head, 7);
	
	int n = 5;
	
	cout << "Linked list before modification: \n";
	dispaly(head);

	head = removeNthFromEnd(head, 5);
	cout << "Linked list after modification: \n";
	dispaly(head);

	return 0;
}
