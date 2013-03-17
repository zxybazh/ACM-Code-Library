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

int prime[200], prime_num;
LL ans[200], p[200], c[2222][2222], base;

class MegaFactorialDiv2 {
public:
    bool check(int x) {
        for (int i = 2; i * i <= x; i++)
            if (x % i == 0) return false;
        return true;
    }

	int countDivisors(int N, int K) {
	    base = 1000000009;
	    c[0][0] = 1;
	    for (int i = 1; i <= 2000; i++)
            for (int j = 0; j <= i; j++)
                c[i][j] = (c[i-1][j-1] + c[i-1][j]) % base;
	    prime_num = 1; prime[1] = 2; memset(ans, 0, sizeof(ans));
	    for (int i = 3; i <= 1000; i++) if (check(i)) prime[++prime_num] = i;
	    int j, t;
	    for (int i = 1; i <= N; i++) {
	        for (j = 1, t = i; j <= prime_num && t != 1; j++) {
	            p[j] = 0;
                while (t % prime[j]== 0){
                    t /= prime[j]; p[j]++;
                }
                p[j] = (p[j] * c[N+K-i-1][K-1]) % base;
                ans[j] = (ans[j] + p[j]) % base;
	        }
	    }

	    LL tot = 1;
	    for (int i = 1; i <= prime_num; i++)
            tot = (tot * (ans[i] + 1)) % base;
        return tot;
	}
};
