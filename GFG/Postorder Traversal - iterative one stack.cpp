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
//iterative one stack//
void postOrder(Node* root)
{
  // Your code here
    if(root == NULL) return;
    stack<Node *> s;
    while(1){
        while(root){
          if(root -> right)s.push(root -> right);
          s.push(root);
          root = root -> left;
        }
        if(s.empty())break;
        root = s.top();
        s.pop();
                
        if(root -> right && !s.empty() && root -> right == s.top()){
            s.pop();
            s.push(root);
            root = root -> right;
        }
        else{
            cout<<root->data<<" ";
            root = NULL;
        }
      
    }
  
  
}