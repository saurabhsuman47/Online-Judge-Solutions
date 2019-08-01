
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
    // Function to find middle element a linked list
    int getMiddle(Node head)
   {
        int l = findLen(head);
        if(l == 0)return -1;
        int idx = l/2;
        while(idx-- > 0){
            head = head.next;
        }
        return head.data;
   }
   
   int findLen(Node head){
       int l = 0;
       while(head != null){
           head = head.next;
           l++;
       }
       return l;
   }
}
