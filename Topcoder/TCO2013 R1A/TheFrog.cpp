#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define LD long double
#define VI vector<int>
#define PB push_back
#define typee TheFrog
#define function getMinimum

int maxn, n, dd;
int ll[55], rr[55];

class TheFrog {
public:
    bool check(int x, int y) {
        for (int i = 0; i < n; i++)
            if (rr[i]*y/x - ll[i]*y/x > 1 ||
                (rr[i]*y/x - ll[i]*y/x== 1 &&
                 !(rr[i]*y % x == 0 && rr[i] *y % x == 0)))
                    return false;
        return true;
    };
    double make(int x) {
        if (!x) return 1 << 30;
        for (int i = dd; i >= 1; i--)
        if (x >= i * maxn && check(x, i)) return x/(double)i;
        return 1 << 30;
    }
	double getMinimum(int D, vector <int> L, vector <int> R) {
		maxn = -1;
	    n = L.size(); dd = D;
	    for (int i = 0; i < n; i++) maxn = max(maxn, R[i]-L[i]);
	    for (int i = 0; i < n; i++) {ll[i]=L[i]; rr[i] = R[i];}
	    double ans = 1 << 30;
	    for (int i = 0; i < n; i++) {
	        ans = min(ans, make(L[i]));
	        ans = min(ans, make(R[i]));
	    }
	    return ans;
	}
};
