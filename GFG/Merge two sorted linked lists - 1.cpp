/* Link list Node  
struct Node {
    int data;
    Node* next;
}; */

Node* SortedMerge(Node* head1,   Node* head2)
{
    // Your Code Here
    Node *head = NULL;
    Node *curr = NULL;
    
    while(head1 && head2){
        int temp_data;
        if(head1 -> data > head2 -> data){
            temp_data = head2 -> data;
            head2 = head2 -> next;
        }
        else{
            temp_data = head1 -> data;
            head1 = head1 -> next;
        }
        Node *temp = new Node();
        temp -> data = temp_data;
        if(head == NULL){
            head = temp;
            curr = head;
        }
        else{
            curr -> next = temp;
            curr = curr -> next;
        }
    }
    while(head1){
        Node *temp = new Node();
        temp -> data = head1 -> data;
        head1 = head1 -> next;
        if(head == NULL){
            head = temp;
            curr = head;
        }
        else{
            curr -> next = temp;
            curr = curr -> next;
        }
    }
    while(head2){
        Node *temp = new Node();
        temp -> data = head2 -> data;
        head2 = head2 -> next;
        if(head == NULL){
            head = temp;
            curr = head;
        }
        else{
            curr -> next = temp;
            curr = curr -> next;
        }
    }
    return head;
}