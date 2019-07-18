public class Solution {
    public class Node{
        public long count;
        public ArrayList<Integer> arr;
        
        public Node(long count, ArrayList<Integer> arr){
            this.count = count;
            this.arr = arr;
        }
    }
    
    ArrayList<ArrayList<Node>> sol = new ArrayList<>();
    ArrayList<Integer> B;
    
    public ArrayList<Integer> rodCut(int A, ArrayList<Integer> B) {
        
        this.B = B;
        B.add(0, 0);
        B.add(B.size(), A);
        int m = B.size();
        for(int i = 0; i < m; i++){
            ArrayList<Node> t1 = new ArrayList<Node>();
            for(int j = 0; j < m; j++){
                t1.add(null);
            }
            sol.add(t1);
        }
        // System.out.println(helper(0, m-1, B, sol).count);

        
        return helper(0, m-1).arr;

    }
    
    public Node helper(int i, int j){
        
        if (i >= j) return null;
        if(i + 1 == j) return new Node(0, new ArrayList<Integer>());
        if(sol.get(i).get(j) != null) return sol.get(i).get(j);
        ArrayList<Integer> tempArr = new ArrayList<Integer>();
        long minSum = 100000000000000000l;
        
        
        for(int k = i + 1; k <= j - 1; k ++){
            Node left = helper(i, k);
            Node right = helper(k, j);
            if(left.count + right .count  < minSum){
                minSum = left.count + right .count;
                tempArr = new ArrayList<Integer>();
                tempArr.add(B.get(k));
                for(int kk = 0; kk < left.arr.size(); kk++){
                    tempArr.add(left.arr.get(kk));
                }
                for(int kk = 0; kk < right.arr.size(); kk++){
                    tempArr.add(right.arr.get(kk));
                }
            }
        }
        
        sol.get(i).add(j,  new Node(minSum + B.get(j) - B.get(i), tempArr));
        return sol.get(i).get(j);
        
    }
}

