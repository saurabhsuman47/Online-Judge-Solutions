 /* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node {
    int data;
    Node* left, * right;
}; */

//returns true if all values of that subtree are between min and max/, called recursively for all subtree/
bool isBstUtil(Node *root, int min, int max){
    if(!root) return true;
    if(root -> data < min || root -> data > max)return false;
    return isBstUtil(root -> left, min, (root -> data) - 1) && isBstUtil(root -> right, (root -> data) + 1, max);
}

/* Should return true if tree represented by root is BST. 
   For example, return  value should be 1 for following tree.
         20
     /      \ 
   10       30
  and return value should be 0 for following tree.
         10
     /      \ 
   20       30 */
//recursive//
bool isBST(Node* root) {
    // Your code here
    return isBstUtil(root, INT_MIN, INT_MAX);
    
}

