/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Computes the height of binary tree with given root.  */
//iterative//
int height(Node* root)
{
   // Your code here
   if(root == NULL)return 0;
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   int count = 0;
   while(!q.empty()){
       Node *temp = q.front();
       q.pop();
       if(temp == NULL){
          count++;
          if(!q.empty())q.push(NULL);
       }
       else {
           if(temp -> left)q.push(temp -> left);
           if(temp -> right)q.push(temp -> right);
       }
   }
   return count;
   
   
}
