import java.io.*;
import java.util.*;

public class Pro_Erl_11 {
	
    public static void main(String args[]) throws IOException{
    	File The_File_To_Open = new File("/home/zxybazh/javaz/test1/src/in.txt");
    	FileInputStream fin = new FileInputStream(The_File_To_Open);
    	Scanner cin = new Scanner(fin);
    	int n; long ans;
    	long a[][] = new long[22][22];
    	n = 20; ans = 0;
    	for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) a[i][j] = cin.nextLong();
    	for (int i = 0; i < n-3; i++)
    		for (int j = 0; j < n-3; j++) {
    			ans = max(ans, a[i][j]*a[i+1][j+1]*a[i+2][j+2]*a[i+3][j+3]);
    			ans = max(ans, a[i][j]*a[i+1][j]*a[i+2][j]*a[i+3][j]);
    			ans = max(ans, a[i][j]*a[i][j+1]*a[i][j+2]*a[i][j+3]);
    		}
    	for (int i = 0; i < n-3; i++)
    		for (int j = 3; j <= n; j++)
    			ans = max(ans, a[i][j]*a[i+1][j-1]*a[i+2][j-2]*a[i+3][j-3]);
    	System.out.println(ans);
    }

	private static long max(long a, long b) {
		return (a>b?a:b);
	}
}

