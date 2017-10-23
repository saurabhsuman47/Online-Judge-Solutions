/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */


/*you are required to 
complete this function */
//recursive//
bool hasPathSum(Node *node, int sum)
{
   //Your code here
   if(node == NULL){
       if(sum == 0)return true;
       else return false;
   } 
   if(!node -> left && !node -> right && node -> data == sum)return true;
   else{
       bool t1 = false,t2 = false;
       if(node -> left)t1 = hasPathSum(node -> left, sum - (node -> data));
       if(node -> right)t2 = hasPathSum(node -> right, sum - (node -> data));
       return t1 | t2;
   }
}
