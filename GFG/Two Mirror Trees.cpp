/* Node structure
struct Node
{
    int data;
    Node* left, *right;
}; */

/* Given two trees, should return true if they are
   mirror of each other. */
//recursive//
int areMirror(Node* a, Node* b)
{
   // Your code here
   if(!a && !b)return 1;
   if(!a || !b)return 0;
   if(a-> data != b -> data)return 0;
   return areMirror(a -> left, b -> right) & areMirror(a -> right, b -> left);
}

