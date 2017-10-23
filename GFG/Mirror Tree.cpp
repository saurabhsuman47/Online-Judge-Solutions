/* A binary tree node has data, pointer to left child
   and a pointer to right child /
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should convert tree to its mirror */
//recursive//
void mirror(Node* root) 
{
    // Your Code Here
    if(!root)return;
    Node *temp = root -> right;
    root -> right = root -> left;
    root -> left = temp;
    mirror(root -> left);
    mirror(root -> right);
}