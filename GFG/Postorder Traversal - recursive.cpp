{
    int data;
    Node* left;
    Node* right;
}; */

/* Prints postorder traversal of Binary Tree.  In output
   all keys should be separated by space. For example
  postorder traversal of below tree should be "20 30 10"
         10
       /      \ 
    20       30 */
//recursive//
void postOrder(Node* root)
{
  // Your code here
  if(root == NULL)return;
  postOrder(root -> left);
  postOrder(root -> right);
  cout<<root->data<<" ";
}
