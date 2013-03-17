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
#define LL long long
#define fo(i, l, r) for (int i = l; i <= r; i++)

using namespace std;

string a[3];
LL n[3];

class AlternateColors {
public:
	string getColor(long long r, long long g, long long b, long long k) {
		a[0] = "RED";
		a[1] = "GREEN";
		a[2] = "BLUE";
		n[0] = r;
		n[1] = g;
		n[2] = b;
		while (true){
			LL l = -1;
			fo (i, 0, 2)
				if (n[i] != 0){
					l++;
					n[l] = n[i];
					a[l] = a[i];
				}
            fo (i, (int) (l + 1), 2) n[i] = 0;
			LL tmp = (LL) 1000000 * (LL) 1000000 + (LL) 1;
			fo(i, 0, l) tmp = min(tmp, n[i]);
			if (k <= (l + 1) * tmp){
				int m = (k - 1) % (l + 1);
				return a[m];
			} else{
				k -= (l + 1) * tmp;
				fo(i, 0, l) n[i] -= tmp;
			}
		}
	}
};
