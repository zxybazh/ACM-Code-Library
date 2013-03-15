import java.util.Scanner;
public class Main{
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int l = cin.nextInt();
		int[] h = new int[1111];
		for (int i = 1; i<= l; i++) h[i] = 0;
		int n = cin.nextInt();
		int[][] a = new int[1111][2];
		int m1 = 0, a1 = 0, m2 = 0, a2 = 0;
		for (int i = 1; i <= n; ++i) {
			a[i][0] = cin.nextInt();
			a[i][1] = cin.nextInt();
			if (a[i][1] - a[i][0] + 1 > m1) {
				m1 = a[i][1] - a[i][0] + 1;
				a1 = i;
			}
		}
		System.out.println(a1);
		for (int i = 1; i <= n; i++) {
			int t = 0;
			for (int j = a[i][0]; j <= a[i][1]; j++)
				if (h[j] == 0) {h[j] = 1; t++;}
			if (t > m2) {
				m2 = t; a2 = i;
			}
		}
		System.out.println(a2);
	}
}