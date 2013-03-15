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
#define MP make_pair
#define typee WolfPackDivTwo
#define function calc

#define INF (0x3f3f3f3f)
#define base 1000000007
long long fac[55], wfac[55];

class WolfPackDivTwo {
public:
    bool check(int x1, int y1, int x2, int y2, int m) {
        int d = abs(x1-x2)+abs(y1-y2);
        if (d > m) return false;
        return !((m-d) & 1);
    }
	LL pow(LL x, int y) {
        LL ans = 1;
        for (;y;y >>= 1, x = x * x % base)
        if (y & 1) ans = (ans * x) % base;
        return ans;
    }
    LL calc(int x1, int y1, int x2, int y2, int m) {
        int d = abs(x1-x2)+abs(y1-y2);
        d = (m-d) / 2;
        int f1 = abs(x1-x2);
        int f2 = abs(y1-y2);
        int f3=0,f4=0;
        LL ans = 0;
        for (int i = 0; i <= d; i++) {
            f1 += i; f3 += i;
            f2 += d-i; f4 += d-i;
            ans = (ans + fac[m]* wfac[f1]% base * wfac[f2] % base * wfac[f3] % base * wfac[f4] % base) % base;
            f1 -= i; f3 -= i;
            f2 -= d-i; f4 -= d-i;
        }
       return ans;
    }
	int calc(vector <int> x, vector <int> y, int m) {
	    fac[0] = 1;
	    for (int i = 1; i < 55; i++) fac[i] = fac[i-1] * i % base;
	    for (int i = 0; i < 55; i++) wfac[i] = pow(fac[i], base - 2);
	    int n = x.size();
	    LL ans = 0;
	    for (int i =-111; i < 222; i++)
            for (int j = -111; j < 222; j++) {
                bool flag = true;
                for (int k = 0; k < n; k++)
                    if (!check(x[k], y[k], i, j, m)) {flag = false; break;}
                if (!flag) continue;
                LL tans = 1;
                for (int k = 0; k < n; k++)
                    tans = tans * calc(x[k], y[k], i, j, m) % base;
                ans =(ans + tans) % base;
            }
        return (int)ans;
	}
};
