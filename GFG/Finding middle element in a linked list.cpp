/* Link list Node 
struct Node {
    int data;
    Node* next;
}; */

/* Should return data of middle node. If linked list is empty, then  -1*/
int getMiddle(Node *head)
{
   if(head == NULL)return -1;
   else if(head -> next == NULL)return head -> data;
   else{
       Node *ptr1 = head, *ptr2 = head;
       while(ptr2 && ptr2 -> next){
            ptr1 = ptr1 -> next;
            ptr2 = ptr2 -> next -> next;
       }
       return ptr1 -> data;
   }
}

