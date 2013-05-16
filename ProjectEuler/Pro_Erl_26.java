import java.io.*;
import java.util.HashMap;
import java.util.Scanner;

public class Pro_Erl_26 {
	public static Scanner cin = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
    	int tmp, ml =- 0, ma = 0;
    	for (int i = 2; i < 1000; i++) {
    		tmp = calc(i);
    		if (tmp > ml) {
    			ml = tmp; ma = i;
    		}
    	}
    	System.out.println(ma);
    }
	private static int calc(int x) {
		HashMap<Integer, Integer> map = new HashMap<Integer, Integer>();
		int tmp = 10, k = 1;
		for (;;k++) {
			if (map.containsKey(tmp)) return  k-map.get(tmp);
			map.put(tmp,k);
			tmp = tmp % x * 10;
			if (tmp == 0) return 0;
		}
	}
}