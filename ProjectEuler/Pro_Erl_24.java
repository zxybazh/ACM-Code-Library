import java.io.*;

public class Pro_Erl_24 {
	static int a[] = new int[11];
    public static void main(String args[]) throws IOException{
    	for (int i = 0; i < 10; i++) a[i] = i;
    	for (int i = 1; i < 1000000; i++) {
    		Boolean flag = next_permutation(0, 10);
    		if (!flag) {System.out.println("Error!");break;}
    	}
    	for (int i = 0; i < 10; i++) System.out.printf("%d", a[i]);
    	System.out.println();
    }
    private static Boolean next_permutation(int l, int r) {
		if (r-l <= 1) return false;
		int t2, j, k, t1 = r-1;
		for (;;) {
			t2 = t1--;
			if (a[t1] < a[t2]) {
				j = r;
				while (!(a[t1] < a[--j]));
				k = a[t1]; a[t1] = a[j]; a[j] = k;
				reverse(t2, r);
				return true;
			}
			if (t1 == l) {
				reverse(l, r);
				return false;
			}
		}	
    }
    private static void reverse(int l, int r) {
    	int t;
    	for (int i = 0; i < (r-l)/2; i++) {
    		t = a[l+i];	a[l+i] = a[r-i-1]; a[r-i-1] = t;
    	}
    }
}