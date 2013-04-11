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
#define N 5555
#define INF (1ll << 60)

int n, m, k, t, p, x, y, mm[2];
LL num[N], sum[N], nu[N], e[N][3], ans, tans, maxn[2];
struct node {
    int y, next; LL c;
} z[N*3];

void link(int x, int y, int c) {
    z[++t].c = c;
    z[t].y = y;
    z[t].next = z[x].next;
    z[x].next = t;
}

void dfs(int x, int la) {
    num[x] = 1;
    for (int p = z[x].next; p; p = z[p].next)
        if (z[p].y != la) {
            dfs(z[p].y, x);
            num[x] += num[z[p].y];
        }
}

void count_sum(int x, int la) {
    sum[x] = 0; nu[x] = 1;
    for (int p = z[x].next; p; p = z[p].next) {
        if (z[p].y != la) {
            count_sum(z[p].y, x);
            nu[x] += nu[z[p].y];
            sum[x] += sum[z[p].y] + z[p].c * nu[z[p].y];
        }
    }
}

void push_sum(int x, int la, int d) {
    for (int p = z[x].next; p; p = z[p].next) {
        if (z[p].y != la) {
            sum[z[p].y] = sum[x] + z[p].c * (nu[x]-2*nu[z[p].y]);
            nu[z[p].y] = nu[x];
            push_sum(z[p].y, x, d);
        }
    }
    if (sum[x] < maxn[d]) {maxn[d] = sum[x]; mm[d] = x;}
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n); t = n;
    for (int i = 0; i < n-1; i++) {
        scanf("%d%d%d", &x, &y, &p);
        e[i][0] = x; e[i][1] = y; e[i][2] = p;
        link(x, y, p); link(y, x, p);
    }
    dfs(1, 0);
    ans = 1ll << 60;
    for (int i = 0; i < n-1; i++) {
        maxn[0] = maxn[1] = INF; mm[0] = mm[1] = 0;
        for (int j = 0; j < 2; j++) {
            count_sum(e[i][j], e[i][j^1]);
            push_sum(e[i][j], e[i][j^1], j);
        }
        tans = 0;
        for (int j = 1; j <= n; j++) tans += sum[j];
        tans >>= 1;
        tans += e[i][2]*nu[e[i][0]]*nu[e[i][1]] + nu[e[i][1]] * sum[mm[0]] + nu[e[i][0]] * sum[mm[1]];

        if (tans < ans) ans = tans;
    }
    cout << ans << endl;
    return 0;
}

