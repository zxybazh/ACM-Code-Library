import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Pro_Erl_27 {
	public static Scanner cin = new Scanner(System.in);
	static final int N = 2222222;
	static Boolean p[] = new Boolean[N];
	static int prime[] = new int[N];
    public static void main(String args[]) throws IOException{
    	int xx = 0, yy = 0, maxn = 0, t = 0, tmp;
    	Arrays.fill(p, false);
    	p[1] = true;
    	for (int i = 2; i < N; i++) {
            if (!p[i]) {
                prime[++t] = i;
            }
            for (int j = 1; j <= t; j++) {
                if (prime[j] * i >= N) break;
                p[prime[j] * i] =true;
            }
        }
    	for (int a = -999; a < 1000; a++)
    		for (int b = -999; b < 1000; b++) {
        		for (tmp = 0; check(tmp*tmp+a*tmp+b); tmp++);
        		if (tmp > maxn) {
        			maxn = tmp;
        			xx = a; yy = b;
        		}
    		}
    	System.out.printf("%d\n", xx*yy);
    }
	private static Boolean check(int x) {
		return (x > 1  && !p[x]);
	}
}