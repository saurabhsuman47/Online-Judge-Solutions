/*
  Reverse a linked list
  The input list will have at least one element  
  Return the node which points to the head of the new LinkedList
  Node is defined as 
  struct node
  {
     int data;
     struct Node *next;
  }
*/

//overall recursive , iterative reversal for a group//
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
    int count = 0;
    node *curr = head;
    node *prev = NULL;
    node *next = NULL;
    
    while(count < k && curr != NULL){
        next = curr -> next;
        curr -> next = prev;
        prev = curr;
        curr = next;
        count++;
    }
    if(curr != NULL){
        node *ptr = reverse(curr, k);
        head -> next = ptr;
    }
    
    return prev;
}
