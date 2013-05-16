import java.io.*;

public class Pro_Erl_21 {
    public static void main(String args[]) throws IOException{
    	int ans = 0, t;
    	for (int i = 1; i < 10000; i++) {
    		t = calc(i);
    		if (calc(t) == i && i != t) {ans+=i;System.out.printf("%d %d\n", i,t);}
    	}
    	System.out.println(ans);
    	//System.out.println(calc(220));
    }

	private static int calc(int t) {
		int k = (int) Math.sqrt(t);
		int ans = 1;
		for (int i = 2; i <= k; i++){
			if (t % i == 0) ans += i + t/i;
		}
		if (k*k == t && t != 1) ans -= k;
		return ans;
	}
}