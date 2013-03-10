import java.util.*;
import java.math.*;
public class Main{
	public static void main(String args[]) {
		Scanner cin = new Scanner(System.in);
		int n = cin.nextInt();
		int m = cin.nextInt();
		while (n!= 0 || m !=0) {
			BigInteger n1 = BigInteger.ONE, n2 = BigInteger.ONE,n3 = BigInteger.ONE;
			for (int i = 1; i <= n; i++) n1 = n1.multiply(BigInteger.valueOf(i));
			for (int i = 1; i <= m; i++) n2 = n2.multiply(BigInteger.valueOf(i));
			for (int i = 1; i <= n-m; i++) n3 = n3.multiply(BigInteger.valueOf(i));
			n1 = n1.divide(n2); n1 = n1.divide(n3);
			System.out.println(n+" things taken "+m+" at a time is "+n1+" exactly.");
			n = cin.nextInt();
			m = cin.nextInt();
		}
	}
}
