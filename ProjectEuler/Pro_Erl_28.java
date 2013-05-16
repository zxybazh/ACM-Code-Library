import java.io.*;
import java.util.Scanner;

public class Pro_Erl_28 {
	public static Scanner cin = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
    	int ans = 1, t = 1, k = 0;
    	final int N = 1001;
    	for (int i = 1; i <= N / 2; i++) {
    		t += k*4+2; k+=2;
    		ans += t*4+k*6;
    		//System.out.printf("%d %d\n", t, k);
    	}
    	System.out.printf("%d\n", ans);
    }
}