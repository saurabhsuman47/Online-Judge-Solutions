//struct node//
struct Node{
    int data;
    Node *left;
    Node *right;
};

//finds the index of an element from an array, also given the start and end indexes to search between//
int find(int x, int arr[], int start, int end){
    for(int i = start; i <= end; i++){
        if(arr[i] == x)return i;
    }
    return 0;
}

//buildTree - builds the tree//
Node* buildTree(int in[], int pre[], int n, int &idx, int inStart, int inEnd){
    if(idx >=n || inStart > inEnd)return NULL;
    Node *root = new Node();
    root -> data = pre[idx];
    idx++;
    int i = find(root->data, in, inStart, inEnd);
    root -> left = buildTree(in, pre, n, idx, inStart, i - 1);
    root -> right = buildTree(in, pre, n, idx, i + 1, inEnd);
    return root;
}

//calls buildTree and passes parameters//
Node* callBuildTree(int in[], int pre[], int n){
    int idx = 0;
    Node *root = buildTree(in, pre, n, idx, 0 , n-1);
    return root;
}

//post order traversal//
void postOrder(Node *root){
    if(!root)return;
    postOrder(root -> left);
    postOrder(root -> right);
    cout<<root -> data<<" ";
}

/*prints the post order traversal of the 
tree */
//construct the tree then print post order traversal//
void printPostOrder(int in[], int pre[], int n)
{
    //Your code here
    Node * root = callBuildTree(in, pre, n);
    postOrder(root);
    
}
