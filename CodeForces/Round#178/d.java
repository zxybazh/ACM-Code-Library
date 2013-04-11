import java.util.*;

public class Main {
	public static Pair make_pair(int x ,int y) {
		Pair tmp = new Pair(); tmp.a = x; tmp.b=y; return tmp;
	}
	public static Triple make_trip(int x ,int y, int z) {
		Triple tt = new Triple(); tt.a = x; tt.b=y; tt.c = z; return tt;
	}
	static Scanner cin = new Scanner (System.in);
	static Set< Pair > set1 = new HashSet< Pair >();
	static Set< Triple > set2 = new HashSet< Triple >();
	static int x, y;
	public static Boolean check(int xx, int yy) {
		return ((xx+yy) & 1) == ((x+y) & 1);
	}
    public static void main(String args[]) {
    	int n, m, p; String tmp;
    	char c, d; long ans;
    	n = cin.nextInt(); m = cin.nextInt();
    	x = cin.nextInt(); y = cin.nextInt();
    	tmp = cin.next(); c = tmp.charAt(0); d = tmp.charAt(1);    	
    	p = 0; ans = 1;
    	if (c == 'U') p += 2;
    	if (d == 'R') p ++;    	
    	for (int i = 1; i <= m; i++) {
    		if (check(1, i)) set1.add(make_pair(1, i));
    		if (check(n, i)) set1.add(make_pair(n, i));
    	}
    	for (int i = 1; i <= n; i++) {
    		if (check(i, 1)) set1.add(make_pair(i, 1));
    		if (check(i, m)) set1.add(make_pair(i, m));
    	}
    	set1.remove(make_pair(x, y)); int tk = 0;
    	while (set1.size() != 0 && set2.contains(make_trip(x, y, p)) == false) {
    		//System.out.printf("%d %d %d\n", x, y, p);
    		set2.add(make_trip(x, y, p));
    		if (p == 0) {if (n-x < y-1) {p = 2; tk = n-x;} else {p = 1; tk = y-1;} x+=tk; y-=tk;} else
    		if (p == 1) {if (n-x < m-y) {p = 3;	tk = n-x;} else {p = 0;	tk = m-y;} x+=tk; y+=tk;} else
    		if (p == 2) {if (x-1 < y-1) {p = 0; tk = x-1;} else {p = 3; tk = y-1;} x-=tk; y-=tk;} else
   			if (p == 3) {if (x-1 < m-y) {p = 1; tk = x-1;} else {p = 2; tk = m-y;} x-=tk; y+=tk;};
   			ans += tk; set1.remove(make_pair(x, y));
    	}
    	if (set1.size() == 0) System.out.println(ans); else System.out.println(-1);
    }
}

class Pair {
	int a, b;
	@Override
    public boolean equals(Object obj) {
        if (obj == null || a != ((Pair) obj).a || b != ((Pair) obj).b) return false;
        return true;
    }
	@Override  
    public int hashCode() {
		final long base = 1000000007;
		long result = (a * (long)100000 % base + b-1) % base;
        return (int)result;
    }
}

class Triple {
	int a, b, c;
	@Override
	public boolean equals(Object obj) {
		if (obj == null || a != ((Triple) obj).a || b != ((Triple) obj).b || c != ((Triple) obj).c) return false;
        return true;
	}
	@Override  
    public int hashCode() {
		final long base = 1000000007;
		long result = (a*313*313%base + b*313%base + c) % base;
        return (int)result;
    }
}

