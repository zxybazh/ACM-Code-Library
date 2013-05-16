import java.io.*;
import java.math.BigInteger;
import java.util.*;

public class Pro_Erl_13 {
	
    public static void main(String args[]) throws IOException{
    	File The_File_To_Open = new File("/home/zxybazh/javaz/test1/src/in.txt");
    	FileInputStream fin = new FileInputStream(The_File_To_Open);
    	Scanner cin = new Scanner(fin);
    	int n = 100;
    	BigInteger ans = BigInteger.ZERO;
    	for (int i = 0; i < n; i++) ans = ans.add(cin.nextBigInteger());
    	System.out.println(ans);
    }
}

