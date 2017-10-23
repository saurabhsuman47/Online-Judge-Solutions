/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

/* Prints the nodes having no siblings.  */
//iterative//
void printSibling(Node* root)
{
   // Your code here
   vector<int> v;
   queue<Node *> q;
   if(root)q.push(root);
   while(!q.empty()){
       Node * temp = q.front();
       q.pop();
       if(temp -> left && !temp -> right){
           v.push_back(temp -> left -> data);
       }
       if(!temp -> left && temp -> right){
           v.push_back(temp -> right -> data);
       }
       if(temp -> left)q.push(temp -> left);
       if(temp -> right)q.push(temp -> right);
   }
   sort(v.begin(), v.end());
   for(int i = 0; i <v.size(); i++)cout<<v[i]<<" ";
   
}
