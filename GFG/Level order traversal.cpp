/* A binary tree Node
struct Node
{
    int data;
    Node* left, * right;
}; */

//You are required to complete this method
void levelOrder(Node* node)
{
  //Your code here
  queue<Node *> q;
  if(node){
      q.push(node);
      q.push(NULL);
  }
  while(!q.empty()){
      Node *curr = q.front();
      q.pop();
      if(curr == NULL){
          cout<<"$"<<" ";
          if(q.empty())break;
          else{
              q.push(NULL);
              continue;
          }
      }
      
      cout<<curr->data<<" ";
      if(curr -> left)q.push(curr -> left);
      if(curr -> right)q.push(curr -> right);
  }
}
