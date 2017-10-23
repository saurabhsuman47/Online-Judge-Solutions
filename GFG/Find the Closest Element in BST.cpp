/*The Node structure is
struct Node {
int data;
Node * right, * left;
};*/

void maxDiffUtil(Node *root, int k, int &diff, int &res){
    if(!root)return;
    maxDiffUtil(root -> left, k, diff, res);
    int temp_diff = abs((root -> data) - k);
    if(temp_diff <= diff){
        diff = temp_diff;
        res = root -> data;
    }
    maxDiffUtil(root -> right, k, diff, res);
}

/*You are required to complete below method */
//it should be minDiff//
int maxDiff(Node *root, int k)
{
    //Your code here
    int diff = INT_MAX;
    int res = 0;
    maxDiffUtil(root, k, diff, res);
    return res;
    
}

