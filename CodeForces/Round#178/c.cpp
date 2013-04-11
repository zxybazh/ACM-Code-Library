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
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) printf("%d ", x)
#define wl(x) printf("%d\n", x)
#define N 1111

int n, m, k, t, p;
LL a[N], base, ans, ff[N];

LL pow(LL x, LL y) {
    if (x == 1 || y <= 0) return 1;
    LL ans = 1;
    for (; y; y >>= 1, x = x*x%base)
        if (y & 1) ans = ans*x%base;
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re2(n, m); ff[0] = 1;base = 1e9+7; ans = 1;
    for (LL i = 1; i <= 1000; i++) ff[i] = ff[i-1] * i % base;
    for (int i = 0; i < m; i++) {re(p); a[i] = p;}
    sort(a, a + m);
    for (int i = 1; i < m; i++) {
        ans = ans * pow(2ll , a[i]-a[i-1]-2) % base
        * pow(ff[a[i]-a[i-1]-1], base-2) % base;
    }
    if (a[0] != 1) ans = ans * pow(ff[a[0]-1], base-2) % base;
    if (a[m-1] != n) ans = ans * pow(ff[n - a[m-1]], base-2) % base;
    ans = ans * ff[n-m] % base;
    cout << ans << endl;
    return 0;
}

