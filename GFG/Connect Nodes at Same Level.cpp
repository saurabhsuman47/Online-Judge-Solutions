/* struct Node
{
  int data;
  Node *left,  *right;
  Node *nextRight;  // This has garbage value in input trees
}; */

// Should set the nextRight for all nodes
//level order traversal with null pointers to separate levels//
void connect(Node *p)
{
   // Your Code Here
   if (!p)return;
   queue<Node*> q;
   q.push(p);
   q.push(NULL);
   Node *ptr = NULL;
   while(!q.empty()){
       Node *temp = q.front();
       if(ptr)ptr -> nextRight = temp;
       ptr = temp;
       q.pop();
       if(temp == NULL){
           if(!q.empty())q.push(NULL);
       }
       else{
           if(temp -> left)q.push(temp -> left);
           if(temp -> right)q.push(temp -> right);
       }
   }
}


