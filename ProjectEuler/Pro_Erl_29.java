import java.io.*;
import java.math.BigInteger;
import java.util.HashSet;
import java.util.Scanner;
import java.util.Set;

public class Pro_Erl_29 {
	public static Scanner cin = new Scanner(System.in);
	static Set< BigInteger > s = new HashSet< BigInteger >();
    public static void main(String args[]) throws IOException{
    	for (int i = 2; i <= 100; i++)
    		for (int j = 2; j <= 100; j++)	{
    			s.add(BigInteger.valueOf(i).pow(j));
    		}
    	System.out.printf("%d\n", s.size());
    }
}