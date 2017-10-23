// C/C++ program to segregate even and odd nodes in a
// Linked List
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

using namespace std;
 
/* a node of the singly linked list */
struct node
{
    int data;
    struct node *next;
};
 
node* segregateEvenOdd(node *head)
{
    node *heade = NULL, *heado = NULL, *taile = NULL, *tailo = NULL;
    node *curr = head;
    while(curr != NULL){
        if(curr -> data % 2 == 0){
            if(heade == NULL){heade = curr; taile = curr;}
            else{
                taile -> next = curr;
                taile = taile -> next;
            }
            
        }
        else{
            if(heado == NULL){heado = curr; tailo = curr;}
            else{
                tailo -> next = curr;
                tailo = tailo -> next;
            }
        }
        curr = curr -> next;
    }
    
    if(!heade)return heado;
    if(!heado)return heade;
    tailo -> next = NULL;
    taile -> next = heado;
    return heade;
}
 
/* UTILITY FUNCTIONS */
/* Function to insert a node at the beginning  */
void push(struct node** head_ref, int new_data)
{
    /* allocate node */
    struct node* new_node =
        (struct node*) malloc(sizeof(struct node));
 
    /* put in the data  */
    new_node->data  = new_data;
 
    /* link the old list off the new node */
    new_node->next = (*head_ref);
 
    /* move the head to point to the new node */
    (*head_ref)    = new_node;
}
 
/* Function to print nodes in a given linked list */
void printList(struct node *node)
{
    while (node!=NULL)
    {
        printf("%d ", node->data);
        node = node->next;
    }
}
 
/* Drier program to test above functions*/
int main()
{
    int t;
    cin>>t;
    while(t--){
       /* Start with the empty list */
        struct node* head = NULL;
     
        int n;
        cin>>n;
        int a[n];
        for(int i = 0; i<n;i++){
            cin>>a[i];
        }
        for(int i = n-1; i>=0;i--){
            push(&head, a[i]);
        }
        head = segregateEvenOdd(head);
        
        printList(head); 
        cout<<endl;
    }
    
 
    return 0;
}
