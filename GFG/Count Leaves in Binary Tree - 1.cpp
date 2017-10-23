/* A binary tree node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

/* Should return count of leaves. For example, return
    value should be 2 for following tree.
         10
      /      \ 
   20       30 */
//iterative//
int countLeaves(Node* root)
{
  // Your code here
    if(root == NULL)return 0;
    queue<Node *> q;
    q.push(root);
    int count = 0;
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        if(temp -> left == NULL && temp -> right == NULL){
            count++;
        }
        if(temp -> left)q.push(temp -> left);
        if(temp -> right)q.push(temp -> right);
    }
    return count;
    
}
