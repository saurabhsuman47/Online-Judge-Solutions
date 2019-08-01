struct Node
{
    int data;
    Node *left;
    Node *right;
    int height;
};
*/
Node *createNode(int data)
{
    Node *newNode = new Node;
    newNode->data=data;
    newNode->left = newNode->right = NULL;
    newNode->height = 1;
    return newNode;
}
int height(Node *root)
{
    if(root == NULL)
    {
        return 0;
    }
    else
    {
        return root->height;
    }
}
int max(int a,int b)
{
    return (a>b)?a:b;
}
Node *RR(struct Node *y)
{
    struct Node *x = y->left;
    struct Node *T2 = x->right;
 
    // Perform rotation
    x->right = y;
    y->left = T2;
 
    // Update heights
    y->height = max(height(y->left), height(y->right))+1;
    x->height = max(height(x->left), height(x->right))+1;
 
    // Return new root
    return x;
}
 
// A utility function to left rotate subtree rooted with x
// See the diagram given above.
Node *LL(struct Node *x)
{
    struct Node *y = x->right;
    struct Node *T2 = y->left;
 
    // Perform rotation
    y->left = x;
    x->right = T2;
 
    //  Update heights
    x->height = max(height(x->left), height(x->right))+1;
    y->height = max(height(y->left), height(y->right))+1;
 
    // Return new root
    return y;
}
int BF(Node *node)
{
    if(node==NULL)
    {
        return 0;
    }
    return height(node->left)-height(node->right);
}
/*You are required to complete this method */
Node* insertToAVL( Node* node, int data)
{
    if(node == NULL)
    {
        return createNode(data);
    }
    if(data < node->data)
    {
        node->left = insertToAVL(node->left,data);
    }
    else if(data > node->data)
    {
        node->right = insertToAVL(node->right,data);
    }
    else
    {
        return node;
    }
    node->height = max(height(node->left),height(node->right))+1;
    int balance = BF(node);
    if(balance<-1 && data>node->right->data)
    {
        return LL(node);
    }
    if(balance<-1 && data<node->right->data)
    {
        node->right = RR(node->right);
        return LL(node);
    }
    if(balance>1 && data < node->left->data)
    {
        return RR(node);
    }
    if(balance>1 && data > node->left->data)
    {
        node->left = LL(node->left);
        return RR(node);
    }
    return node;
    //Your code here
}
