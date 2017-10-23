/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* A binary tree node structure
struct Node {
    int data;
    Node* left, * right;
}; */
// This function should return tree if passed  tree 
// is balanced, else false.  Time complexity should
//  be O(n) where n is number of nodes in tree

int isBalancedHelper(Node *root){
    if(root == NULL)return 0;
    if(!(root -> left) && !(root -> right)){
        return 1;
    }
    int t1 = isBalancedHelper(root -> left);
    int t2 = isBalancedHelper(root -> right);
    if(t1 < 0 || t2 < 0)return -1;
    if(abs(t1 - t2) <= 1)return 1 + max(t1, t2);
    else return -1;
}

bool isBalanced(Node *root)
{
    //  Your Code here
    if(isBalancedHelper(root) < 0)return false;
    return true;
}

