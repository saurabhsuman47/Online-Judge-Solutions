/* The structure of linked list is the following
struct Node
{
   int data;
   Node* next;
};   */

//  function which splits the circular linked list.  head is pointer
// to head Node of given lined list.  head1_ref1 and *head_ref2
// are pointers to head pointers of resultant two halves.

void splitList(Node *head, Node **head1_ref, Node **head2_ref)
{
    // your code goes here
    Node *ptr1 = head, *ptr2 = head;
    while(ptr2 -> next != head){
        if(ptr2 -> next -> next != head){
            ptr2 = ptr2 -> next -> next;
            ptr1 = ptr1 -> next;
        }
        else{
            ptr2 = ptr2 -> next;
        }
    }
    *head2_ref = ptr1 -> next;
    ptr2 -> next = *head2_ref;
    ptr1 -> next = head;
    *head1_ref = head;
    
}
