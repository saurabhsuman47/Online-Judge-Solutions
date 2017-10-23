/* A tree Node has data, pointer to left child
   and a pointer to right child  
struct Node
{
    int data;
    Node* left;
    Node* right;
}; */

//using stack//
void reversePrint(Node *root)
{
    //Your code here
    stack<int> s;
    queue<Node *> q;
    if(root)q.push(root);
    while(!q.empty()){
        Node *temp = q.front();
        q.pop();
        s.push(temp -> data);
        if(temp -> right)q.push(temp -> right);
        if(temp -> left)q.push(temp -> left);
    }
    while(!s.empty()){
        cout<<s.top()<<" ";
        s.pop();
    }
}
