class Solution {
    class Node{
        int x;
        int y;
        int height;

        Node(int x, int y, int height){
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }

    class NodeComparator implements Comparator<Node> {
        public int compare(Node n1, Node n2) {
            if (n1.height < n2.height)
                return 1;
            else if (n1.height == n2.height && n1.x < n2.x)
                return 1;
            else if (n1.height == n2.height && n1.x == n2.x && n1.y > n2.y)
                return 1;

            return -1;
        }
    }

    public List<List<Integer>> getSkyline(int[][] buildings) {
        PriorityQueue<Node> pq = new PriorityQueue<>(new NodeComparator());
        List<Node> inputList = new ArrayList<>();
        List<List<Integer>> outputList = new ArrayList<>();
        Set<Integer> criticalPoints = new TreeSet<>();
        int idx = 0;
        int processedHeight = 0;

        for(int[] tempArr: buildings) {
            inputList.add(new Node(tempArr[0],tempArr[1], tempArr[2]));
            criticalPoints.add(tempArr[0]);
            criticalPoints.add(tempArr[1]);
        }

        for(Integer i: criticalPoints){
            while(!pq.isEmpty() && pq.peek().y <= i){
                pq.remove();
            }
            while(idx < inputList.size() && inputList.get(idx).x == i){
                pq.add(inputList.get(idx));
                idx++;
            }

            if(pq.isEmpty()){
                outputList.add(new ArrayList<>(Arrays.asList(i, 0)));
                processedHeight = 0;
                continue;
            }
            Node tempNode = pq.peek();
            if(tempNode.height != processedHeight){
                outputList.add(new ArrayList<>(Arrays.asList(i, tempNode.height)));
                processedHeight = tempNode.height;
            }
        }
        return outputList;
    }
}
