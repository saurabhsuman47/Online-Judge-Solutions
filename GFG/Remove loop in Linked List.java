
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete The function
Node is as follows:
class Node {
    int data;
    Node next;
    Node(int d) {
        data = d;
        next = null;
    }
}*/
class GfG{
	  int removeTheLoop(Node node) {
	      Node slow = node;
	      Node fast = node;
	      while(slow != null && fast != null && fast.next != null){
	          slow = slow.next;
	          fast = fast.next.next;
	          if(slow == fast){
	              remove(slow, node);
	          }
	      }
	      return 1;
    }
    void remove(Node ptr, Node head){
        Node prev = null;
        while(ptr != head){
            prev = ptr;
            ptr = ptr.next;
            head = head.next;
        }
        prev.next = null;
    }
}
