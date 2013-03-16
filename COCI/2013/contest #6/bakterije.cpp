#include <map>
#include <set>
#include <cmath>
#include <queue>
#include <stack>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cstring>
#include <cstdlib>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define LD long double
#define VI vector<LL>
#define PB push_back
#define re(x) scanf("%d", &x)
#define re2(x,y) scanf("%d%d", &x, &y)
#define wt(x) prLLf("%d", x)
#define wl(x) prLLf("%d\n", x)
#define K 5
#define N 55
#define INF (1ll << 60)

LL n, m, k, tx, ty;
LL rans;
LL state[K][3], mmap[K][N][N], hash[K][N][N][4];
const LL dx[] = {-1,0,1,0};
const LL dy[] = {0,1,0,-1};
LL ans[K][4][3], st[K];
LL e[K][2], LCM, T;
char c;

void work(LL p, LL x, LL y, LL fx) {
    hash[p][x][y][fx] = 1;
    LL mx, my, mfx, t = 1;
    for (;;) {
        mfx = (fx+mmap[p][x][y]) % 4;
        mx = x + dx[mfx];
        my = y + dy[mfx];
        if (mx < 0 || mx >= n || my < 0 || my >= m) {
            mfx = (mfx + 2) % 4;
            mx = x + dx[mfx];
            my = y + dy[mfx];
        }
        if (!hash[p][mx][my][mfx]) hash[p][mx][my][mfx] = ++t;
        else {t++; break;}
        x = mx; y = my; fx = mfx;
        //cout << t << ":" << mx+1 << " " << my+1 << " " <<mfx << endl;
    }
    for (LL i = 0; i < 4; i++) {
        if (!hash[p][tx][ty][i]) continue;
        if (hash[p][tx][ty][i] < hash[p][mx][my][mfx]) {
            ans[p][i][0] = 1; ans[p][i][1] = hash[p][tx][ty][i] - 1;
        } else {
            ans[p][i][0] = 2; ans[p][i][1] = t - hash[p][mx][my][mfx];
            ans[p][i][2] = hash[p][tx][ty][i] - 1;
        }
    }
}

bool fail;

LL gcd(LL a, LL b) {
    LL c;
    for (;b;c = a % b, a = b, b = c);
    return a;
}

LL lcm(LL a, LL b) {
    return a / gcd(a,b) * b;
}

void exgcd(LL a, LL b, LL &x, LL &y) {
    if (b == 0) {
        x = 1; y = 0;
    } else {
        exgcd(b, a % b, y, x);
        y = y - a / b * x;
    }
}

LL crt(LL n) {
    LCM = 1; T = 0; LL Maxn = 0;
    fail = false;
    for (LL i = 0; i < n; i++) {
        Maxn = max(Maxn, e[i][1]);
        e[i][1] %= e[i][0];
        LL x, y;
        exgcd(e[i][0], LCM, x, y);
        LL tmp = gcd(e[i][0], LCM);
        if ((e[i][1]- T) % tmp) {fail = true; break;}
        else {
            T = T + (e[i][1]-T)/tmp*y%e[i][0]*LCM;
            LCM = lcm(LCM, e[i][0]);
        }
        T = (T % LCM + LCM) % LCM;
        //if (T % e[i][0] != e[i][1]) return INF;
    }
    if (fail) return INF; else {
        while (T < Maxn) T += LCM;
        return T;
    }
}

void solve() {
    bool flag = false;
    for (LL i = 0; i < k; i++)
        flag |= ans[i][st[i]][0] == 1;
    if (flag) {
        LL p = 0;
        for (LL i = 0; i < k; i++)
            if (ans[i][st[i]][0] == 1) p = ans[i][st[i]][1];
        for (LL i = 0; i < k; i++) {
            if (ans[i][st[i]][0] == 1) {
                if (p != ans[i][st[i]][1]) return;
            } else {
                if (p < ans[i][st[i]][2] || (p % ans[i][st[i]][1] !=
                    ans[i][st[i]][2] % ans[i][st[i]][1])) return;
            }
        }
        rans = min(rans, p);
    } else {
        for (LL i = 0; i < k; i++) {
            e[i][0] = ans[i][st[i]][1];
            e[i][1] = ans[i][st[i]][2];
        }
        rans = min(rans, crt(k));
    }
}

void make_state(LL d) {
    if (d == k) solve();
    else for (LL i = 0; i < 4; i++)
    if (ans[d][i][0]) {st[d] = i; make_state(d+1);}
}

int main(){
    //freopen("in.txt", "r", stdin);
	//freopen("ou.txt", "w", stdout);
	memset(hash, 0, sizeof(hash));
	memset(ans, 0, sizeof(ans));
	scanf("%lld%lld%lld", &n, &m, &k);
	scanf("%lld%lld", &tx, &ty); rans = INF;
	tx--; ty--;
	for (LL i = 0; i < k; i++) {
	    scanf("%lld%lld%c", &state[i][0], &state[i][1], &c);
	    state[i][0]--;
	    state[i][1]--;
	    while (c == ' ') scanf("%c", &c);
	    if (c == 'U') state[i][2] = 0; else
	    if (c == 'R') state[i][2] = 1; else
	    if (c == 'D') state[i][2] = 2; else
	    if (c == 'L') state[i][2] = 3;
	    scanf("\n");
	    for (LL j = 0; j < n; j++) {
            for (LL k = 0; k < m; k++) {
                scanf("%c", &c);
                mmap[i][j][k] = c - '0';
            }
            scanf("\n");
	    }
	    work(i, state[i][0], state[i][1], state[i][2]);
	}
	make_state(0);
	if (rans == INF) puts("-1"); else printf("%lld\n", rans+1);
	return 0;
}
