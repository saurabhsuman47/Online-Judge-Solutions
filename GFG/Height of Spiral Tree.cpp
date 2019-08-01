/*Structure of the node of the binary tree
struct Node
{
	int key;
	Node* left, *right;
};
*/

Node* getdll(Node *root){
    while(root){
        if(root -> right && root -> right -> left && root -> right -> left == root)return root;
        else if(root -> left)root = root -> left;
        else root = root -> right;
    }
    return NULL;
}
void breakdll(Node *ptr){
    while(ptr -> right){
        Node *temp = ptr -> right;
        ptr -> right = NULL;
        temp -> left = NULL;
        ptr = temp;
    }
}
int height(Node *root){
    if(!root)return 0;
    return 1 + max(height(root -> left), height(root -> right));
}
// function should return the height of the binary tree
int findTreeHeight(Node* node)
{
	// Code here
	if(!node)return 0;
	Node* dllptr = getdll(node);
	if(dllptr)breakdll(dllptr); //need to check dllptr because of buggy tester code(CDLL might not be present)
	return height(node);
}
