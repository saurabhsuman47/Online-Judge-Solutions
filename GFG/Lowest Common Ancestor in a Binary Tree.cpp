/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

//return true if there is a path from root to node with data n, else false//
//Also fills the vector v(passed with reference) with the nodes in the path from root to the node//
bool findPath(vector<Node *> &v, Node *root, int n){
    if(root == NULL)return false;
    v.push_back(root);
    if(root -> data == n)return true;
    if(findPath(v, root -> left, n) || findPath(v, root -> right, n)){
        return true;
    }
    v.pop_back();
    return false;
}

/*you are required to 
complete this function */
//calculate paths for both nodes and compares them until they diverge//
//O(n) time but two traversals req, O(n) space but vector spaces are req//
Node * LCA(Node* root ,int n1 ,int n2 )
{
   //Your code here 
   vector<Node *> v1, v2;
   if(findPath(v1, root, n1) && findPath(v2, root, n2)){
       Node *res = NULL;
       for(int i = 0; i < min(v1.size(), v2.size()); i++){
           if(v1[i] == v2[i])res = v1[i];
           else break;
       }
       return res;
   }
   else return NULL;
   
}
