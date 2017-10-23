/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
//recursive - O(n) time - only single tree traversal, O(n) space - only recursive stack//
Node * LCA(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   if(root == NULL)return NULL;
   if(root -> data == n1 || root -> data == n2)return root;
   Node *left = LCA(root -> left, n1, n2);
   Node *right = LCA(root -> right, n1, n2);
   if(left && right)return root;
   return (left ? left : right);
   
}