import java.io.*;
import java.math.BigInteger;
import java.util.Scanner;

public class Pro_Erl_20 {
    public static void main(String args[]) throws IOException{
    	File The_File_To_Open = new File("/home/zxybazh/javaz/test1/src/ou.txt");	
    	PrintStream fou = new PrintStream(new FileOutputStream(The_File_To_Open));
    	System.setOut(fou);
    	
    	BigInteger a = BigInteger.ONE;
    	for (int i = 1; i <= 100; i++) a = a.multiply(BigInteger.valueOf(i));
    	System.out.println(a);
    	FileInputStream fin = new FileInputStream(The_File_To_Open);
    	Scanner cin = new Scanner(fin);
    	String s = cin.next();
    	int ans = 0;
    	for (int i = 0; i < s.length(); i++) {
    		ans += s.charAt(i) - '0';
    	}
    	System.out.println(ans);
    }
}