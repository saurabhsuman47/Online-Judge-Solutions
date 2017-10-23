/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
//iterative//
Node* reverse(Node *head)
{
  // Your code here
   if(head == NULL || head -> next == NULL)return head;
    Node *next1 = head -> next;
    head -> next = NULL;
    while(next1 != NULL){ 
        Node *next2 = next1 -> next;
        next1 -> next = head;
        head = next1;
        next1 = next2;
    }
    return head;
  
}