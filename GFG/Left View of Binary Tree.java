
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* A Binary Tree node
class Node
{
    int data;
    Node left, right;
    Node(int item)
    {
        data = item;
        left = right = null;
    }
}*/
class GfG
{
    void leftView(Node root)
    {
        if(root == null)return;
      Queue<Node> mq = new LinkedList<>();
      mq.add(null);
      mq.add(root);
      int flag=0;
      while(true){
          if(mq.peek() == null){
              mq.remove();
              mq.add(null);
              flag = 1;
          }
          Node temp = mq.remove();
          
          if(temp == null)break;
          
          if(temp.left != null)mq.add(temp.left);
              if(temp.right != null)mq.add(temp.right);
              if(flag==1)System.out.print(temp.data + " ");
              flag=0;
          
      }
    }
}
