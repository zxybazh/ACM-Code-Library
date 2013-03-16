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
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) printf("%d", x)
#define wl(x) printf("%d\n", x)
#define N 11111

int n, m, k, t, p;
int a[N];
LL f[2][N];
LL base;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n); memset(f, 0, sizeof(f));
    f[0][0] = 1; base = 1e9+7;
    for (int i = 0; i < n; i++) re(a[i]);
    if (a[0] > 0) {printf("0\n"); return 0;}
    for (int i = 1; i < n; i++) {
        int t = i & 1;
        memset(f[t], 0, sizeof(f[t]));
        if (a[i] != -1) f[t][a[i]] = (f[t^1][a[i]] + (a[i]>=1 ?f[t^1][a[i] - 1]:0) + f[t^1][a[i] + 1]) % base;
        else for (int j = 0; j <= min(i, n-1-i); j++)
            f[t][j] = (f[t^1][j] + f[t^1][j+1] + (j >= 1 ? f[t^1][j-1] : 0)) % base;
    }
    printf("%lld\n", f[(n-1) & 1][0]);
    return 0;
}
