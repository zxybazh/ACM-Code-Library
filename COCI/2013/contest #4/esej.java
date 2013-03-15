import java.util.Scanner;
public class Main{
	static int ans = 0;
	static Scanner cin = new Scanner(System.in);
	static String s;
	static char h[] = new char[1111111];
	public static void work(){
		s = cin.nextLine();
		int r = 0;
		for(int i = 0; i < s.length(); ++i)
			if (r > 0 && s.charAt(i) == h[r]) r--;
				else h[++r] = s.charAt(i);
		if (r == 0) ans++;
	}
	public static void main(String args[]) {
		int n = cin.nextInt();
		s = cin.nextLine();
		for (int i = 0; i < n; i++) work();
		System.out.println(ans);
	}
}