import java.io.*;

public class Pro_Erl_12_2 {
	static final int base = 3000;
	static final int N = 1111111;
	static long a[] = new long[N+10];
    public static void main(String args[]) throws IOException{
    	for (int i = 1; i <= N; i++)
    		for (int j = i; j <= N; j+=i) a[j]++;
    	for (int i = 1; i <= N; i++)
    		if (check(i)) {
    			System.out.println(i*(long)(i+1)/2); break;
    		}
    	}

	private static boolean check(int n) {
		if ((n & 1) == 1) return a[n]*(long)a[(n+1)/2] >= base;
		else return a[n/2]*(long)a[n+1] >= base;
	}
}