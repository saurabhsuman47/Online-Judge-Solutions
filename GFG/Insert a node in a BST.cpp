/* The structure of a BST node is as follows:
struct node {
  int data;
  struct node * right, * left;
}; */

/* This function should insert a new node with given data and
   return root of the modified tree  */
//recursive//
struct node* insert(struct node* root, int x)
{
    // Your code here
    if(root == NULL){
        root = new node();
        root -> data = x;
        root -> left = NULL;
        root -> right = NULL;
        return root;
    }
    
    if(root -> data == x)return root;
    
    if(x < root -> data){
        root -> left = insert(root -> left, x);
    }
    else{
        root -> right = insert(root -> right, x);
    }
    
    return root;
    
}
