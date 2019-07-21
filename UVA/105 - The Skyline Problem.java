/* IMPORTANT: class must not be public. */


import java.io.BufferedReader;
import java.io.IOException;
import java.io.InputStreamReader;
import java.util.*;


class Main {

    static class Node{
        int x;
        int y;
        int height;

        Node(int x, int y, int height){
            this.x = x;
            this.y = y;
            this.height = height;
        }
    }

    static class NodeComparator implements Comparator<Node> {
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

    public static void main(String args[] ) throws Exception {

        String input;
        StringTokenizer idata;
        int x, y, height;

        PriorityQueue<Node> pq = new PriorityQueue<>(new NodeComparator());
        ArrayList<Node> inputList = new ArrayList<>();
        Set<Integer> criticalPoints = new TreeSet<>();
        int idx = 0;
        int processedHeight = 0;

        while ((input = Main.ReadLn (255)) != null) {
            idata = new StringTokenizer (input);
            x = Integer.parseInt (idata.nextToken());
            height = Integer.parseInt (idata.nextToken());
            y = Integer.parseInt (idata.nextToken());

            inputList.add(new Node(x,y, height));
            criticalPoints.add(x);
            criticalPoints.add(y);
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
                System.out.println(i + " 0");
                processedHeight = 0;
                continue;
            }
            Node tempNode = pq.peek();
            if(tempNode.height != processedHeight){
                System.out.print(i + " " + tempNode.height + " ");
                processedHeight = tempNode.height;
            }
        }
    }

    //from https://uva.onlinejudge.org/data/p100.java.html
    static String ReadLn (int maxLg)  // utility function to read from stdin
    {
        byte lin[] = new byte [maxLg];
        int lg = 0, car = -1;
        String line = "";

        try
        {
            while (lg < maxLg)
            {
                car = System.in.read();
                if ((car < 0) || (car == '\n')) break;
                lin [lg++] += car;
            }
        }
        catch (IOException e)
        {
            return (null);
        }

        if ((car < 0) && (lg == 0)) return (null);  // eof
        return (new String (lin, 0, lg));
    }
}
