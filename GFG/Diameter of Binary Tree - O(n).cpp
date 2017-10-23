/* Tree node structure  used in the program
 struct Node
 {
     int data;
     Node* left, *right;
}; */

int* calculateDiameterHeight(Node* root){
    int *result = new int[2];
    result[0] = 0; result[1] = 0;
    if(root == NULL){
        return result;
    }
    int *left_result, *right_result;
    left_result = calculateDiameterHeight(root -> left);
    right_result = calculateDiameterHeight(root -> right);
    int t1 = max(left_result[0], right_result[0]);
    int t2 = 1 + left_result[1] + right_result[1];
    result[0] = max(t1, t2);
    result[1] = 1 + max(left_result[1] , right_result[1]);
    return result;
    
}

/* Computes the diameter of binary tree with given root.  */
//recursive O(n) time - calculate height and diameter of a node in same single level//
int diameter(Node* root)
{
   // Your code here
   int *result = calculateDiameterHeight(root);
   return result[0];
   
}

