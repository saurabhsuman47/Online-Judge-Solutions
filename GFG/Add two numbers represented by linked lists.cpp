
/*struct Node
{
    int data;
   Node* next;
}; */
//write a function returns the resultant linked list
Node*  addTwoLists(Node* head1, Node* head2){
  Node* head = NULL;
  Node* ptr = head;
  int carry = 0;
  while(head1 || head2){
      if(!head){
          head = new Node();
          ptr = head;
      }
      else{
          ptr -> next = new Node();
          ptr = ptr -> next;
      }
      int x = 0, y = 0;
      if(head1){
          x = head1 -> data; 
          head1 = head1 -> next;
      }
      if(head2){
          y = head2 -> data;
          head2 = head2 -> next;
      }
      int sum = x + y + carry;
      ptr -> data = sum % 10;
      carry = sum /10;
  }
  if(carry){
      ptr -> next = new Node();
      ptr = ptr -> next;
      ptr -> data = carry;
  }
  if(ptr)ptr -> next = NULL;
  return head;
}
