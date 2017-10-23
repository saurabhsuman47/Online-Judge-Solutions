/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/*  Tree node
struct Node
{
    int data;
    Node* left, * right;
}; */
// Should return true if tree is Sum Tree, else false
bool isSumTree(Node* root)
{
     // Your code here
     if(!root|| (!(root -> left) && !(root -> right)))return true;
     bool b1 = isSumTree(root -> left);
     bool b2 = isSumTree(root -> right);
     if((b1 & b2) == false)return false;
     int sum = 0;
     if(root -> left){
         sum += root -> left -> data;
         if((root -> left -> left) || (root -> left -> right)){
             sum += root -> left -> data;
         }
     }
     if(root -> right){
         sum += root -> right -> data;
         if((root -> right -> left) || (root -> right -> right)){
             sum += root -> right -> data;
         }
     }
     //sum += ((root -> left) ? root -> left -> data : 0);
     //sum += ((root -> right) ? root -> right -> data : 0);
     if(root -> data == sum)return true;
     return false;
}
