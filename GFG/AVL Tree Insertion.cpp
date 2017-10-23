/* The structure of the Node is
struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/

Node* createNewNode(int data){
	Node *ptr = new Node();
	ptr -> data = data;
	ptr -> left = NULL;
	ptr -> right = NULL;
	ptr -> height = 0;
	return ptr;
}

int height(Node *root){
	if(root == NULL)return -1;
	else return root -> height;
}

void updateHeight(Node *root){
    if(!root)return;
	root -> height = max(height(root -> left) , height(root -> right)) + 1;
}

int balanceFactor(Node *root){
	if(!root)return 0;
	return height(root -> left) - height(root -> right);
}

Node* leftRotate(Node *z){
	Node *y = z -> right;
	z -> right = y -> left;
	y -> left = z;
	updateHeight(z);
	updateHeight(y);
	return y;
}

Node* rightRotate(Node *z){
	Node *y = z -> left;
	z -> left = y -> right;
	y -> right = z;
	updateHeight(z);
	updateHeight(y);
	return y;	
}

Node* insertToAVL(Node *root, int data){
	if(root == NULL){
		root = createNewNode(data);
		return root;
	}
	if(data < root -> data)root -> left = insertToAVL(root -> left, data);
	else if(data > root -> data) root -> right = insertToAVL(root -> right, data);
	else return root;
	
	updateHeight(root);
	//left heavy unbalanced
	if(balanceFactor(root) > 1){
		//left left case
		if(data < root -> left -> data){
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
		if(data > root -> right -> data){
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
