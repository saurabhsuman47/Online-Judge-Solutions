
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/*Complete the function below
Node is as follows:
class Node{
	int data;
	Node next;
	Node(int d){
		data=d;
		next=null;
	}
}
*/
class GfG
{
	public void rotate(Node head,int k)
        {
            if(k!=0){
            
                Node temp = head;
                Node kth = null;
                int l = 1;
                while(temp.next != null){
                    if(l == k){
                        kth = temp;
                    }
                    temp = temp.next;
                    l++;
                }
                if(kth == null) kth = temp;
                temp.next = head;
                head = kth.next;
                kth.next = null;
            }
            print(head);
            
        }
    public void print(Node head){
        while(head != null){
            System.out.print(head.data);
            System.out.print(" ");
            head = head.next;
        }
    }
    
}
