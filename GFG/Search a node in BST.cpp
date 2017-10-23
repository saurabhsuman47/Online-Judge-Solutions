/* Node structure 
struct node {
    int data;
   struct node * right, * left;
};*/


/*You are required to complete this method*/
//recursive//
bool search(node* root, int x)
{
    //Your code here
    if(!root)return false;
    if(root -> data == x)return true;
    if(x < root -> data)return search(root -> left, x);
    else return search(root -> right, x);
}

