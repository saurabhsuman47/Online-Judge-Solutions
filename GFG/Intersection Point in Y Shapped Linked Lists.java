
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node of a linked list
 class Node {
   int data;
    Node next;
    Node(int d)  { data = d;  next = null; }
}
 Linked List class
class LinkedList
{
    Node head;  // head of list
}
This is method only submission.  You only need to complete the method. */
class GFG
{
	int intersectPoint(Node headA, Node headB)
	{
        int l1 = len(headA);
        int l2 = len(headB);
        int diff = (l1 - l2) > 0? (l1-l2) : (l2-l1);
        if(l1 > l2){
            for(int i = 0; i < diff; i++){
                headA = headA.next;
            }for(int i = 0; i < diff; i++){
                headA = headA.next;
            }
        }
        else{
            for(int i = 0; i < diff; i++){
                headB = headB.next;
            }
        }
        
        while(headA != null && headB != null){
            if(headA == headB){
                return headA.data;
            }
            headA = headA.next;
            headB = headB.next;
        }
        return 0;
        
	}
	
	int len(Node head){
	    int res = 0;
	    while(head != null){
	        res++;
	        head = head.next;
	    }
	    return res;
	}
}
