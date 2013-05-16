import java.io.*;
import java.util.Arrays;
import java.util.Scanner;

public class Pro_Erl_22 {
    public static void main(String args[]) throws IOException{
    	File The_File_To_Open = new File("/home/zxybazh/javaz/test1/src/names.txt");
    	FileInputStream fin = new FileInputStream(The_File_To_Open);
    	Scanner cin = new Scanner(fin);
    	String st = cin.nextLine();
    	String s[] = st.split(",");
    	int num = 0, t, ans= 0;
    	for (int i = 0; i < st.length(); i++) if (st.charAt(i) == ',') num++;
    	for (int i = 0; i <= num; i++) s[i] = s[i].substring(1, s[i].length()-1);
    	Arrays.sort(s);
    	for (int i = 0; i <= num; i++) {
    		t = 0;
    		for (int j = 0; j < s[i].length(); j++) t+=s[i].charAt(j) - 'A'+1;
    		ans += t*(i+1);
    	}
    	System.out.println(ans);
    }
}