
import java.util.*;
import java.lang.*;
import java.io.*;

class GFG {
	public static void main (String[] args) {
        Scanner sc = new Scanner(System.in);
        int t = sc.nextInt();
        for(int z = 0; z < t; z++){
            int n = sc.nextInt();
            int res = 0;
            for(int i = 0; i < n; i++){
                res = res ^ sc.nextInt();
            }
            System.out.println(res);
        }
    }
}
