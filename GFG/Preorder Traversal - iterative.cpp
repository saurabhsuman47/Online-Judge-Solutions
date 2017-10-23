/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Prints preorder traversal of Binary Tree.  In output
   all keys should be separated by space. For example
  preorder traversal of below tree should be "10 20 30"
         10
       /      \ 
    20       30 */
//iterative//
void preorder(Node* root)
{
  // Your code here
  stack<Node *> s;
  if(root)s.push(root);
  while(!s.empty()){
      Node *temp = s.top();
      cout<<temp->data<<" ";
      s.pop();
      if(temp -> right)s.push(temp -> right);
      if(temp -> left)s.push(temp ->left);
  }
  return;
}