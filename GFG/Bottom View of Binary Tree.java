
/*Please note that it's Function problem i.e.
you need to write your solution in the form of Function(s) only.
Driver Code to call/invoke your function is mentioned above.*/

/* Tree node class
class Node {
    int data; //data of the node
    int hd; //horizontal distance of the node
    Node left, right; //left and right references
    public Node(int key)
    {
        data = key;
        hd = Integer.MAX_VALUE;
        left = right = null;
    }
}*/
class GfG
{
    // Should print bottom view of tree with given root
    Map<Integer, Node> map = new TreeMap<>();
    Map<Integer, Integer> hvMap = new HashMap<>();
    public void bottomView(Node root)
    {
        // Your code here
        util(root, 0, 0);
        for(Map.Entry<Integer, Node> e:map.entrySet()){
            System.out.print(e.getValue().data + " ");
        }
    }
    public void util(Node root, int hlevel, int vlevel){
        if(root == null)return;
        if(!(hvMap.containsKey(hlevel) && hvMap.get(hlevel) > vlevel)){
             map.put(hlevel, root);
             hvMap.put(hlevel, vlevel);
        }
        util(root.left, hlevel - 1, vlevel + 1);
        util(root.right, hlevel + 1, vlevel + 1);
    }
}
	
