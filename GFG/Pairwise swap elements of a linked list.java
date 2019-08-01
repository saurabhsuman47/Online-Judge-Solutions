
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/


/*node class of the linked list
class Node
{
    int data;
    Node next;
    Node(int key)
    {
        data = key;
        next = null;
    }
}*/
// complete the below function
class GfG
{
    public static void pairwiseSwap(Node node)
    {
        while(node != null && node.next != null){
            int temp = node.data;
            node.data = node.next.data;
            node.next.data = temp;
            node = node.next.next;
        }
        
        
       
       
    }
    
   
}
