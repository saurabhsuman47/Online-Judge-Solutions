/*The structure of linked list is the following
struct Node
{
int data;
Node* next; 
};*/

/*The function removes the loop from the linked list if present
You are required to complete this method*/
void removeTheLoop(Node *node)
{
     //Your code here
    Node *ptr1 = node, *ptr2 = node;
    if(ptr1 == NULL)return;
    
    while(ptr1 && ptr2 && ptr2->next){
        ptr1 = ptr1 -> next;
        ptr2 = ptr2 -> next -> next;
        if(ptr1 == ptr2){
            ptr1 = node;
            Node* temp = ptr2;
            while(ptr1 != ptr2){
                temp = ptr2;
                ptr1 = ptr1 -> next;
                ptr2 = ptr2 -> next;
            }
            temp -> next = NULL;
            break;
        }
    }
    
}
