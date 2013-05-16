import java.io.*;

public class Pro_Erl_12 {
    public static void main(String args[]) throws IOException{
    	//File The_File_To_Open = new File("/home/zxybazh/javaz/test1/src/in.txt");
    	//FileInputStream fin = new FileInputStream(The_File_To_Open);
    	//Scanner cin = new Scanner(fin);
    	long n = 1, i = 1;
    	while (!check(n)) n += ++i;
    	System.out.println(n);
    }
    private static Boolean check(long x) {
    	int ans = 0, t = (int) Math.sqrt(x);
    	for (int i = 1; i < t; i++) {
    		if (x % i == 0) ans++;
    		if (x % (x/i) == 0) ans++;
    	}
    	if (t*t==x) ans--;
    	return (ans >= 500);
    }
}