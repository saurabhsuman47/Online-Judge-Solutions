/* The structure of a BST Node is as follows:
struct Node 
{
    int data;
    Node * right, * left;
}; */

//recursive - inorder for ascending order//
void printNearNodes(Node *root, int l, int r)
{
  // your code goes here  
  if(!root)return;
  printNearNodes(root -> left, l, r);
  if(root -> data >= l && root -> data <= r)cout<<root->data<<" ";
  printNearNodes(root -> right, l, r);
}
