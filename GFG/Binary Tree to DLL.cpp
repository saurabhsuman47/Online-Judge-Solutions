

/* Structure for tree and linked list
struct Node
{
    int data;
    // left is used as previous and right is used
    // as next in DLL
    Node *left, *right;
}; */

struct LR{
    Node *left, *right;
};

LR* foo(Node *ptr){
    //cout<<"abc "<<ptr -> data<<endl;
    Node *l = ptr, *r = ptr;
    if(ptr -> left){
        LR *temp = foo(ptr -> left);
        ptr -> left = temp -> right;
        temp -> right -> right= ptr;
        l = temp -> left;
    }
    if(ptr -> right){
        LR *temp = foo(ptr -> right);
        ptr -> right = temp -> left;
        temp -> left -> left = ptr;
        r = temp -> right;
    }
    LR *res = new LR();
    res -> left = l;
    res -> right = r;
    return res;
}
// This function should convert a given Binary tree to Doubly
// Linked List
// root --> Root of Binary Tree
// head_ref --> Pointer to head node of created doubly linked list
void BToDLL(Node *root, Node **head_ref)
{
    if(!root){
        *head_ref = NULL;
    }
    else *head_ref = foo(root) -> left;
}
