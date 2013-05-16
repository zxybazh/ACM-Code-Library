import java.io.*;
import java.util.Scanner;

public class Pro_Erl_30 {
	public static Scanner cin = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
    	int ans = 0;
    	for (int i = 2; i < 1000000; i++) {
    		if (check(i)) ans+= i;
    	}
    	System.out.printf("%d\n", ans);
    }
	private static boolean check(int n) {
		int ans = 0, tn = n;
		for (;n != 0; n /= 10) {
			ans += Math.pow(n % 10, 5);
		}
		return (ans == tn);
	}
}