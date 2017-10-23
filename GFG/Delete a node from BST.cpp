/* The structure of a BST Node is as follows:
struct Node {
  int data;
  Node * right, * left;
}; */

Node* findMin(Node *root){
    if(root == NULL)return NULL;
    if(root -> left)return findMin(root -> left);
    else return root;
}

Node * deleteNode(Node *root,  int x)
{
    // your code goes here   
    if(!root) return root;
  
    if(x < root -> data)root -> left = deleteNode(root -> left, x);
    else if(x > root -> data)root -> right = deleteNode(root -> right, x);
    else{
        if(!root -> left && !root -> right){
            delete root;
            return NULL;
        }
        else if(!root -> left){
            Node *temp = root;
            root = root -> right;
            delete temp;
            return root;
        }
        else if(!root -> right){
            Node *temp = root;
            root = root -> left;
            delete temp;
            return root;
        }
        else{
            Node *temp = findMin(root -> right);
            root -> data = temp -> data;
            root -> right = deleteNode(root -> right, temp -> data);
            return root;
        }
    }
    return root;
}
