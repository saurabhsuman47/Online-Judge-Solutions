
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		//code
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int k = sc.nextInt();
		    int n = sc.nextInt();
		    Queue<Integer> q = new PriorityQueue<Integer>(k, new qComparator());
		    for(int i = 0; i < n; i++){
		        int temp = sc.nextInt();
		        if(q.size() < k - 1){
		            q.add(temp);
		            System.out.print("-1 ");
		        }
		        else if(q.size() == k - 1){
		            q.add(temp);
		            System.out.print(q.peek()  + " ");
		        }
		        else{
		            if(temp >= q.peek()){
		                q.poll();
		                q.add(temp);
		            }
		            System.out.print(q.peek() + " ");
		        }
		    }
		    System.out.println();
		}
	}
	
	
}

public class qComparator implements Comparator<Integer>{
	    public int compare(Integer lhs, Integer rhs){
	        return lhs - rhs;
	    }
	    
	}
