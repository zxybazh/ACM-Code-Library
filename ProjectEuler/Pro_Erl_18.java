import java.io.*;
import java.util.Scanner;

public class Pro_Erl_18 {
    public static void main(String args[]) throws IOException{
    	File File_To_Open = new File("/home/zxybazh/javaz/test1/src/in.txt");
    	FileInputStream fin = new FileInputStream(File_To_Open);
    	Scanner cin = new Scanner(fin);
    	long a[][] = new long[111][111], f[][] = new long[111][111], ans = 0;
    	for (int i = 1; i <= 15; i++)
    		for (int j = 1; j <= i; j++)
    			a[i][j] = cin.nextLong();
    	f[1][1] = a[1][1];
    	for (int i = 2; i <= 15; i++) {
    		for (int j = 2; j < i; j++)
    			f[i][j] = max(f[i-1][j-1], f[i-1][j]) + a[i][j];
    		f[i][1] = f[i-1][1] + a[i][1];
    		f[i][i] = f[i-1][i-1] + a[i][i];
    	}
    	for (int i = 1; i <= 15; i++) ans = max(ans, f[15][i]);
    	System.out.println(ans);
    }

	private static long max(long x, long y) {
		return (x > y ? x : y);
	}
}