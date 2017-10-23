/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/*You are required to complete below method */
//level order traversal with pushing NULL at end of each level, maintain a local and global max and update//
int maxLevelSum(Node * root)
{
   //Your code here
   if(root == NULL)return 0;
   int gmax = INT_MIN;
   int tmax = 0;
   queue<Node *> q;
   q.push(root);
   q.push(NULL);
   while(!q.empty()){
       Node *temp = q.front();
       q.pop();
       if(temp == NULL){
           if(!q.empty())q.push(NULL);
           if(tmax > gmax)gmax = tmax;
           tmax = 0;
       }
       else{
           tmax += temp -> data; 
           if(temp -> left)q.push(temp -> left);
           if(temp -> right)q.push(temp -> right);
       }
   }
   return gmax;
}
