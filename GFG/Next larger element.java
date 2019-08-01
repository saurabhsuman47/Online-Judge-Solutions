
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    Stack<Integer> st = new Stack<Integer>();
		    int[] arr = new int[n];
		    int[] arr1 = new int[n];
		    for(int i = 0 ; i < n; i++){
	            arr[i] = sc.nextInt();
		    }
		    for(int i = 0 ; i < n; i++){
	            while(!st.empty() && arr[st.peek()] < arr[i]){
	                arr1[st.peek()] = arr[i];
	                st.pop();
	            }
	            st.push(i);
		    }
		    while(!st.empty()){
		        arr1[st.peek()] = -1;
		         st.pop();
		    }
		    for(int i = 0 ; i < n; i++){
	            System.out.print(arr1[i] + " ");
		    }
		    System.out.println();
		}
		
	}
}
