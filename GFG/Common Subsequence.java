
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG{
	public static void main (String[] args) {
		Scanner sc = new Scanner(System.in);
		int t = sc.nextInt();
		for(int z = 0; z < t; z++){
		    String s1 = sc.next();
		    String s2 = sc.next();
		    int[] arr = new int[26];
		    int flag = 0;
		    for(int i = 0; i < s1.length(); i++){
		        arr[s1.charAt(i) - 'A']++;
		    }
		    for(int i = 0; i < s2.length(); i++){
		       if(arr[s2.charAt(i) - 'A'] > 0){
		           System.out.println(1);
		           flag = 1;
		           break;
		       }
		    }
		    if(flag == 0){
	           System.out.println(0);
		    }
		}
	}
}
