/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

//calculate height of tree - 1 based//
int height(Node *root){
    if(root == NULL)return 0;
    return 1 + max(height(root -> left) , height(root -> right));
}

/* Computes the diameter of binary tree with given root.  */
//recursive O(n^2) time//
int diameter(Node* root)
{
   // Your code here
   if(root == NULL)return 0;
   int t1 = max(diameter(root -> left), diameter(root -> right));
   int t2 = 1 + height(root -> left) + height(root -> right);
   return max(t1, t2);
}


