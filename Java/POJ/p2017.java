import java.util.*;
public class Main{
	public static void main(String args[]){
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		while (n != -1) {
			int ans = 0, x, y, t = 0;
			for (int i = 0; i < n; i++) {
				x = cin.nextInt();
				y = cin.nextInt();
				ans += (y-t) * x;
				t = y;
			}
			System.out.printf("%d miles\n", ans);
			n = cin.nextInt();
		}
	}
}
