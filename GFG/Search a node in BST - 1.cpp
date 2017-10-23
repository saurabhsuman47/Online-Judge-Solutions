/* Node structure 
struct node {
    int data;
   struct node * right, * left;
};*/


/*You are required to complete this method*/
//iterative//
bool search(node* root, int x)
{
    //Your code here
    if(!root)return false;
    while(root){
        if(root -> data == x)return true;
        if(x < root -> data)root = root -> left;
        else root = root -> right;
    }
    return false;
}


