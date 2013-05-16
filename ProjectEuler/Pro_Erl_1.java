import java.io.*;

public class Pro_Erl_1 {
    public static void main(String args[]) throws IOException{
    	final int T = 1000-1;
    	int x = T/3, y = T/5, z = T/15;
    	//System.out.println(x);
    	//System.out.println(y);
    	//System.out.println(z);
    	x = x*(x+1)/2*3;
    	y = y*(y+1)/2*5;
    	z = z*(z+1)/2*15;
    	System.out.println(x+y-z);
    }
}