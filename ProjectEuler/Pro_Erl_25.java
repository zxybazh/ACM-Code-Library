import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Pro_Erl_25 {
	public static Scanner cin = new Scanner(System.in);
    public static void main(String args[]) throws IOException{
    	BigInteger x = BigInteger.ONE, y = BigInteger.ONE, z;
    	int p = 1;
    	for (;x.toString().length() < 1000; p++) {
    		z = x.add(y);
    		x = y; y = z;
    	}
    	System.out.println(p);
    }
}