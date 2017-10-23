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
//iterative//
void inOrder(Node* root)
{
  // Your code here
  stack<Node *> s;
  int done = 0;
  while(!done){
      while(root != NULL){
          s.push(root);
          root = root -> left;
      }
      if(!s.empty()){
          cout<<s.top()->data<<" ";
          root = s.top() -> right;
          s.pop();
          
          
      }
      else{
          done = 1;
      }
  }
}