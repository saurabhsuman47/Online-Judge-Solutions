
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
    public static int swap(int a, int b){
        return a;
    }
    
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		while(t-- > 0){
		    int n = sc.nextInt();
		    int[] arr = new int[n];
		    for(int i = 0; i < n; i++){
		        arr[i] = sc.nextInt();
		    }
		    int j = 0, k = 1;
		    int flag = 0;
		    while(k < n){
		        if(flag == 0){
		            if(arr[k] < arr[j]){
		                arr[k] = swap(arr[j], arr[j] = arr[k]);
		            }
		        }
		        else{
		            if(arr[j] < arr[k]){
		                arr[k] = swap(arr[j], arr[j] = arr[k]);
		            }
		        }
		        flag = (flag + 1)%2;
		        j++;
		        k++;
		    }
		   
		   for(int i = 0; i < n; i++){
		        System.out.print(arr[i]);
		        System.out.print(" ");
		   }
		   System.out.println();
		    
		}
	}
}
