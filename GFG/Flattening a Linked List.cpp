/*
Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function would be added by GfG's Online Judge.*/


/* Node structure  used in the program
struct Node{
	int data;
	struct Node * next;
	struct Node * bottom ;
}; */
/*  Function which returns the  root of 
    the flattened linked list. */
Node *merge(Node *root1, Node *root2){
    if(!root1){
        return root2;
    }
    else if(!root2){
        return root1;
    }
    else{
        if(root1 -> data > root2 -> data){
            root2 -> bottom = merge(root1, root2 -> bottom);
            return root2;
        }
        else{
            root1 -> bottom = merge(root1 -> bottom, root2);
            return root1;
        }
    }
    
}
// Node *transform(Node *root){
//     if(!root)return root;
//     transform(root -> next);
//     root -> next = root -> bottom;
//     return root;
    
// }

Node *flatten(Node *root)
{
   // Your code here
   if(!root)return NULL;
   Node *temp, *next;
   temp = root;
   next = root -> next;
   while(next){
       Node *temp2 = next -> next;
       temp = merge(temp, next);
       next = temp2;
   }
   return temp;
}
