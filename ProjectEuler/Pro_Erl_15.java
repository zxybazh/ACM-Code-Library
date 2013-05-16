import java.io.*;

public class Pro_Erl_15 {
    public static void main(String args[]) throws IOException{
    	long a[][] = new long[22][22];
    	for (int i = 0; i <= 20 ; i++) a[i][0] = a[0][i] = 1;
    	for (int i = 1; i <= 20 ; i++)
    		for (int j = 1; j <= 20; j++)
    			a[i][j] = a[i-1][j]+a[i][j-1];
    	System.out.println(a[20][20]);
    }
}