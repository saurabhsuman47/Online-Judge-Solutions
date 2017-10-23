/* The structure of a BST node is as follows:
struct node {
  int data;
  struct node * right, * left;
}; */

node* createNode(int x){
    node *temp = new node();
    temp -> data = x;
    temp -> left = NULL;
    temp -> right = NULL;
    return temp;
}

/* This function should insert a new node with given data and
   return root of the modified tree  */
//iterative//
struct node* insert(struct node* root, int x)
{
    // Your code here
    node *temp = root;
    if(!root){
        return createNode(x);
    }
    while(root){
        if(root -> data == x)break;
        if(x < root -> data){
            if(root -> left)root = root -> left;
            else{
                root -> left = createNode(x);
                break;
            }
        }
        else{
            if(root -> right)root = root -> right;
            else{
                root -> right = createNode(x);
                break;
            }
        }
    }
    return temp;
}