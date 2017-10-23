/*The structure of the Node is
struct Node
{
    int data;
    struct Node* next;
};*/

//recursive reverse
Node* reverse(Node *head){
    if(head == NULL || head -> next == NULL)return head;
    Node *ptr = reverse(head -> next);
    head -> next -> next = head;
    head -> next = NULL;
    return ptr;
}

/*You are required to complete this method */
bool isPalindrome(Node *head)
{
    //Your code here
    if(head -> next == NULL)return true;
    Node *ptr1 = head, *ptr2 = head;
    while(ptr2 -> next && ptr2 -> next -> next){
        ptr2 = ptr2 -> next -> next;
        ptr1 = ptr1 -> next;
    }
    
    Node *ptr3 = reverse(ptr1 -> next);
    ptr1 -> next = ptr3;
    int flag = 0;
    ptr2 = head;
    while(ptr3 != NULL){
        if(ptr2 -> data != ptr3 -> data){
            flag = 1;
            break;
        }
        ptr2 = ptr2 -> next;
        ptr3 = ptr3 -> next;
    }
    if(flag == 0)return true;
    else return false;
    
}
