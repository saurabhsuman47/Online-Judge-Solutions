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

//recursive function for reversing one group//
struct node *reverseHelper(struct node *head, int k){
    if(k == 1 || !head || head -> next == NULL )return head;
    node *ptr = reverseHelper(head -> next, k-1);
    head -> next -> next = head;
    head -> next = NULL;
    return ptr;    
}

//overall recursive
struct node *reverse (struct node *head, int k)
{ 
  // Complete this method
    node *temp = head;
    int kk = k;
    while(kk >= 1 || !temp){
        temp = temp -> next;
        kk--;
    }
    node *ptr = reverseHelper(head, k);
    if(temp == NULL)return ptr;
    node *ptr1 = reverse(temp, k);
    temp -> next = ptr;
    return ptr1;
}
