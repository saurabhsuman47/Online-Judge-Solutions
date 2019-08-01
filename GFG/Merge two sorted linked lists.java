
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Merge two linked lists 
  head pointer input could be NULL as well for empty list
  Node is defined as 
    class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }
*/
class gfg
{
    Node MergeLists(Node headA, Node headB) {
        if(headA == null) return headB;
        if(headB == null) return headA;
        
        Node start = new Node(0);
        Node ptr = start;
        while(headA != null && headB != null){
            if(headA.data < headB.data){
                ptr.next = headA;
                headA = headA.next;
            }
            else{
                ptr.next = headB;
                headB = headB.next;
            }
            ptr = ptr.next;
        }
        if(headA != null){
            ptr.next = headA;
        }
        else{
            ptr.next = headB;
        }
        return start.next;
   } 
}
