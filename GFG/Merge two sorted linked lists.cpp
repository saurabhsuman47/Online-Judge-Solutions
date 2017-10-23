/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */

Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
     Node *newnode = new Node();    
    //newnode -> next = NULL;
    Node *temp = newnode;
    while(head1 && head2){
        if(head1 -> data > head2 -> data){
            temp -> next = head2;
            head2 = head2 -> next;            
        }
        else{
            temp -> next = head1;
            head1 = head1 -> next;
        }
        temp = temp -> next;
    }
    if(head1){
        temp -> next = head1;
    }
    if(head2){
        temp -> next = head2;
    }
    temp = newnode -> next;
    free(newnode);
    return temp;
}
