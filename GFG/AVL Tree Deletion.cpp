/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/


void updateHeight(Node *root){
    if(!root)return;
	root -> height = max(height(root -> left) , height(root -> right)) + 1;
}

int balanceFactor(Node *root){
	if(!root)return 0;
	return height(root -> left) - height(root -> right);
}

Node* findMinValueNode(Node *root){
    if(!root)return NULL;
    if(!root -> left)return root;
    return findMinValueNode(root -> left);
}



//Delete a node with data to AVL//
Node* deleteNode(Node *root, int data){
	if(!root){
		return root;
	}
	if(data < root -> data)root -> left = deleteNode(root -> left, data);
	else if(data > root -> data) root -> right = deleteNode(root -> right, data);
	else{
		if(!root -> left && !root -> right){
			delete root;
			return NULL;
		}
		else if(!root -> left){
			Node *temp = root -> right;
			delete root;
			root = temp;
		}
		else if(!root -> right){
			Node *temp = root -> left;
			delete root;
			root = temp;
		}
		else{
			Node *temp = findMinValueNode(root -> right);
			root -> data = temp -> data;
			root -> right = deleteNode(root -> right, temp -> data);
		}
		
	}
	if(!root)return NULL;
	updateHeight(root);
	//left heavy unbalanced
	if(balanceFactor(root) > 1){
		//left left case
		if(balanceFactor(root -> left) >= 0){
			root = rightRotate(root);
		}
		//left right case
		else{
			root -> left = leftRotate(root -> left);
			root = rightRotate(root);
		}
	}
	else if(balanceFactor(root) < -1){
		//right right case
		if(balanceFactor(root -> right) <= 0){
			root = leftRotate(root);
		}
		//right left case
		else{
			root -> right = rightRotate(root -> right);
			root = leftRotate(root);
		}
	}
	return root;
}