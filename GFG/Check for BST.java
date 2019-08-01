
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*  A Binary Search Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
} */
class GfG
{
    int maxNow = -1;
    int isBST(Node root)  
    {
        if(root == null) return 1;
        int cleft = isBST(root.left);
        if(root.data < maxNow){
            return 0;
        }
        else{
            maxNow = root.data;
        }
        int cright = isBST(root.right);
        return cleft&cright;
    }
}
