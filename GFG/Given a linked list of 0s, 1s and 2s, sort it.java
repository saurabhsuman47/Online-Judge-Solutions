
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*
  Sort the list of 0's,1's and 2's
  The input list will have at least one element  
  Node is defined as 
  class Node {
 int value;
  Node next;
  Node(int value) {
   this.value = value;
  }
}
*/
class GFG
{
void linksort(Node head)
{

    int[] arr = new int[3];
    Node node = head;
    while(node != null){
        arr[node.value]++;
        node = node.next;
    }
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < arr[i]; j++){
            head.value = i;
            head = head.next;
        }
    }
    
}  
}
