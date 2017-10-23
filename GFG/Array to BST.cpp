#include <iostream>
using namespace std;

struct Node{
    int data;
    Node *left;
    Node *right;
};

//recursive - find mid element, call on left and right subtree//
Node* arrToBst(int arr[], int left, int right){
    if(left > right)return NULL;
    int mid = (left + right) / 2; //be careful, check what the question says, for this ques #nodes_right >= #nodes_left
    Node *n = new Node();
    n -> data = arr[mid - 1];
    n -> left = arrToBst(arr, left, mid - 1);
    n -> right = arrToBst(arr, mid + 1, right);
    return n;
}

void preorder(Node *root){
    if(root == NULL)return;
    cout<<root -> data<<" ";
    preorder(root -> left);
    preorder(root -> right);
}

int main() {
	//code
	int t;
	cin>>t;
	while(t--){
	    int n;
	    cin>>n;
	    int arr[n];
	    for(int i = 0; i < n; i++){
	        cin>>arr[i];
	    }
	    Node *root = arrToBst(arr, 1, n);
	    preorder(root);
	    cout<<endl;
	    
	}
	return 0;
}
