/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Prints inorder traversal of Binary Tree.  In output
   all keys should be separated by space. For example
  inorder traversal of below tree should be "20 10 30"
         10
       /      \ 
   20       30 */
//recursive//
void inOrder(Node* root)
{
  // Your code here
  if(root == NULL)return;
  inOrder(root -> left);
  cout<<root -> data<<" ";
  inOrder(root -> right);
}