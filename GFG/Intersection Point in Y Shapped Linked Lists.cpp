/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Link list Node 
struct Node {
    int data;
    struct Node* next;
}; */
/* Should return data of intersection point of two linked
   lists head1 and head2.
   If there is no intersecting point, then return -1. */
int len(Node *head){
    int temp = 0;
    while(head){
        temp++;
        head = head -> next;
    }
    return temp;
}
int intersectPoint(Node* head1, Node* head2)
{
    // Your Code Here
    int len1 = len(head1);
    int len2 = len(head2);
    if(len1 * len2 == 0)return -1;
    if(len1 > len2){
        for(int i = 0; i < (len1 - len2); i++)head1 = head1 -> next;
    }
    else{
        for(int i = 0; i < (len2 - len1); i++)head2 = head2 -> next;
    }
    while(head1){
        if(head1 == head2){
            return head1 -> data;
        }
        else{
            head1 = head1 -> next;
            head2 = head2 -> next;
        }
    }
    return -1;
}
