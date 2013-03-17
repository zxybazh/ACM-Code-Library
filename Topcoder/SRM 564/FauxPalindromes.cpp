#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#define fo(i, l, r) for(int i = l; i <= r; i++)

using namespace std;


class FauxPalindromes {
public:
	string classifyIt(string word) {
		char a[111];
		char b[111];
		int n;
		n = word.length();
		fo(i, 0, n - 1) a[i + 1] = word[i];
		bool flg = true;
		fo(i, 1, n /2)
			flg &= (a[i] == a[n - i + 1]);
		if (flg) return "PALINDROME";
		int m;
		m = 0;
		a[0] = a[1] - 1;
		fo(i, 1, n)
			if (a[i] != a[i - 1]){
				m++;
				b[m] = a[i];
			}
		flg = true;
		fo(i, 1, m/2)
			flg &= (b[i] == b[m - i + 1]);
		if (flg) return "FAUX";
		return "NOT EVEN FAUX";
	}
};
