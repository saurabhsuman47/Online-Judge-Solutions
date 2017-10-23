/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Computes the height of binary tree with given root.  */
//recursive//
int height(Node* root)
{
   // Your code here
   if(root == NULL)return 0;
   return (1 + max(height(root -> left) , height(root -> right)));
}
