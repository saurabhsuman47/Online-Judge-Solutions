
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Node is defined as 
class Node
    {
        int data;
        Node next;
        Node(int d) {data = d; next = null; }
    }*/
class GfG
{
 int detectLoop(Node head)
  {
     if(head == null)return 0;
    Node slow = head;
    Node fast = head.next;
    while(fast != null){
       if(slow == fast){
           return 1;
       }
       slow = slow.next;
       if(fast.next != null)fast = fast.next.next;
       else break;
   }
   
   return 0;
    }
}
