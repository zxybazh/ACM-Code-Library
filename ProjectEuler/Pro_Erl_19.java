import java.io.*;

public class Pro_Erl_19 {
    public static void main(String args[]) throws IOException{
    	int ans = 0;
    	final int days[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    	int year = 1901, month = 1, day = 366 % 7;
    	while (year != 2001) {
    		if (day == 0) ans++;
    		day = day + days[month-1];
    		if (month == 2 && check(year)) day++; day %= 7;
    		month++; if (month == 13) {year++;month = 1;}
    	}
    	System.out.println(ans);
    }

	private static boolean check(int x) {
		return (x % 400 == 0 || ((x % 100 != 0) && (x % 4 == 0)));
	}
}