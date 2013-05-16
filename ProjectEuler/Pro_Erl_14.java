import java.io.*;

public class Pro_Erl_14 {
    public static void main(String args[]) throws IOException{
    	long hash[] = new long[1111111];
    	long ma, ml, x, t;
    	ma = ml = 0;
    	for (int i = 1; i <= 1000000; i++) {
    		x = i; t = 1;
    		while (x != 1) {
    			t++;
    			if (x % 2 == 1) x = 3*x+1; else x >>= 1;
    			if (x < i) {t+=hash[(int)x]; x=1;}
    		}
    		if (t > ml) {ml = t; ma = i;}
    		hash[i] = t;
    	}
    	System.out.println(ma);
    }
}