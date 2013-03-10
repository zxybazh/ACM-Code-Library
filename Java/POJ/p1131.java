import java.util.*;
import java.math.*;
public class Main{
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		BigDecimal eight = new BigDecimal(8.0);
		String s;
		while (cin.hasNext()) {
			s = cin.nextLine();
			BigDecimal ans = new BigDecimal(0);
			BigDecimal base = new BigDecimal(1);
			for(int i = 2; i < s.length(); i++) {
				base  = base.divide(eight);
				ans = ans.add(base.multiply(new BigDecimal(s.charAt(i) - '0')));
			}
			System.out.println(s + " [8] = " + ans +" [10] ");
		}
	}
}
