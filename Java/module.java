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

	public static Pair make_pair(int x ,int y) {
		Pair tmp = new Pair(); tmp.a = x; tmp.b=y; return tmp;
	}
	public static Triple make_trip(int x ,int y, int z) {
		Triple tt = new Triple(); tt.a = x; tt.b=y; tt.c = z; return tt;
	}
