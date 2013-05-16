import java.io.*;
import java.util.Arrays;

public class Pro_Erl_23 {
    public static void main(String args[]) throws IOException{
    	Boolean hash[] = new Boolean[1111111];
    	Arrays.fill(hash, false);
    	int ans = 0;
    	Boolean flag;
    	for (int i = 1; i <= 28123; i++) hash[i] =  (calc(i) > i);
    	for (int i = 1; i <= 28123; i++) {
    		flag =  true;
    		for (int j = 1; j <= i-1; j++)
    			if (hash[j] && hash[i-j]) {
    				flag = false; break;
    			}
    		if (flag) {ans += i; System.out.printf("%d\n", i);}
    	}
    	System.out.println(ans);
    }
    private static int calc(int t) {
		int k = (int) Math.sqrt(t);
		int ans = 1;
		for (int i = 2; i <= k; i++){
			if (t % i == 0) ans += i + t/i;
		}
		if (k*k == t) ans -= k;
		return ans;
	}
}