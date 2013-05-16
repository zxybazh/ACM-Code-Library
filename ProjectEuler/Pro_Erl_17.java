import java.io.*;
import java.util.Scanner;

public class Pro_Erl_17 {
    public static void main(String args[]) throws IOException{
    	File File_To_Open = new File("/home/zxybazh/javaz/test1/src/17_dict.txt");
    	FileInputStream fin = new FileInputStream(File_To_Open);
    	Scanner cin = new Scanner(fin);
    	String s[] = new String[111];
    	int ans = 0;
    	for (int i = 1; i <= 100; i++) {
    		s[i] = cin.nextLine();
    		s[i] = s[i].replace(" ","");
    		s[i] = s[i].replace("-","");
    		ans += s[i].length();
    		//System.out.println(s[i]);
    	}
    	for (int i = 101; i < 1000; i++) {
    		if (i % 100 != 0) ans += s[i/100].length()+10+s[i%100].length();
    			//System.out.printf("%s hundred and %s\n", s[i / 100], s[i%100]);
    		else ans += s[i/100].length()+7;
    			//System.out.printf("%s hundred\n", s[i / 100]);
    	}
    	//System.out.println("one thousand");
    	ans += 11;
    	System.out.println(ans);
    }
}