/*  the node structure is as follows 
struct Node
{
int data;
Node* next;
Node* arb;
};*/

// Should return the head of the copied linked list the 
//output will be 1 if successfully copied
Node * copyList(Node *head)
{
    Node *temp = head;
    Node *temp2, *temp3;
    while(temp!=NULL){
        temp2 = new Node();
        temp2 -> data = temp -> data;
        temp2 -> next = temp -> arb;
        temp2 -> arb = NULL;
        temp -> arb = temp2;
        temp = temp -> next;
    }
    
    //create arb for new nodes
    temp = head;
    while(temp != NULL){
        temp2 = temp -> arb;
        if(temp2 -> next)temp2 -> arb = temp2 -> next -> arb;
        temp = temp -> next;
    }
    
    //create next and repair old nodes
    temp = head;
    head = head -> arb;
    while(temp != NULL){
        temp2 = temp -> arb;
        temp3 = temp2 -> next;
        if(temp -> next)temp2 -> next = temp -> next -> arb;
        else temp2 -> next = NULL;
        temp -> arb = temp3;
        temp = temp -> next;
    }
   return head;
}
