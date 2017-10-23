/*The structure of a BST Node is as follows:
struct Node {
    int data;
    Node * right, * left;
};*/

/*You are required to complete
this function*/
//iterative//
Node* LCA(Node *root, int n1, int n2)
{
   //Your code here
   while(root){
       if(n1 < root -> data && n2 < root -> data)root = root -> left;
       else if(n1 > root -> data && n2 > root -> data)root = root -> right;
       else return root;
   }
   return root;
   
}