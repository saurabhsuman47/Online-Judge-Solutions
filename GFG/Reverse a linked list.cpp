/* Linked List Node structure
   struct Node  {
     int data;
     Node *next;
  }
*/

// Should reverse list and return new head.
//recursive//
Node* reverse(Node *head)
{
  // Your code here
  if(head == NULL || head -> next == NULL)return head;
  Node *temp = head -> next;
  head -> next = NULL;
  Node * res = reverse(temp);
  temp->next = head;
  return res;
  
}
