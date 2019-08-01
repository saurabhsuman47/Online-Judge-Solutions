
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Structure of node
class Node
{
    int data;
    Node next;
    Node(int d) {data = d; next = null; }
}
*/
class GfG
{
    int getNthFromLast(Node head, int n)
    {
        Node last = head;
        for(int i = 0; i < n; i++){
            if(last == null)return -1;
            last = last.next;
        }
        while(last != null){
            head = head.next;
            last = last.next;
        }
        return head.data;
    }
}
	
