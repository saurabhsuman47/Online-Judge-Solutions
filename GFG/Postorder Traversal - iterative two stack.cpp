/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
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
//iterative//
void postOrder(Node* root)
{
  // Your code here
  stack<Node *> s;
  stack<int> output;
  if(root)s.push(root);
  while(!s.empty()){
      Node *curr = s.top();
      s.pop();
      output.push(curr -> data);
      if(curr -> left)s.push(curr -> left);
      if(curr -> right)s.push(curr -> right);
  }
  while(!output.empty()){
      cout<<output.top()<<" ";
      output.pop();
  }
  
}