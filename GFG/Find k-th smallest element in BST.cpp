/*Complete the function below
Node is as follows:
struct Node
{
    int data;
    int lCount;
 
    Node* left;
    Node* right;
};*/

void KthSmallestElementUtil(Node *root, int k, int &res, int &count){
    if(!root || count > k)return;
    KthSmallestElementUtil(root -> left, k, res, count);
    count++;
    if(count == k)res = root -> data;
    KthSmallestElementUtil(root -> right, k, res, count);
}
int KthSmallestElement(Node *root, int k)
{
    //add code here.
    int res, count = 0;
    KthSmallestElementUtil(root, k, res, count);
    return res;
}
