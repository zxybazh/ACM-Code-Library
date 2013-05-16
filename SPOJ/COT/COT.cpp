#include <algorithm>
#include <iostream>
#include <cstdio>
#include <cmath>
using namespace std;
typedef long long LL;
typedef unsigned int uit;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
#define N 101010
#define maxint 0x7fffffff
#define Chmtree_Size 4101010
#define E 101010*2
#define V 101010

int n, m, d[N];

struct Chmtree_Node {int lc, rc, sum;};
int node_num;
Chmtree_Node z[Chmtree_Size];

inline void Chmtree_init() {
    node_num = 0;
    z[0].sum = z[0].lc = z[0].rc = 0;
}

inline void insert(int x, uit l, uit r, int p) {
    while (l < r) {
        z[x].sum++;
        if (p <= ((l+r)>>1)) {
            z[++node_num] = z[z[x].lc];
            z[x].lc = node_num;
            r = (l+r) >> 1; x = z[x].lc;
        } else {
            z[++node_num] = z[z[x].rc];
            z[x].rc = node_num;
            l = ((l+r) >> 1) + 1; x = z[x].rc;
        }
    }
    z[x].sum++;
}

int T[N];

inline int ques(int x1, int x2, int x3, int d, uit l, uit r, int k) {
    int ans;
    while (l < r) {
        ans = z[z[x1].lc].sum + z[z[x2].lc].sum - 2*z[z[x3].lc].sum + (l <= d && d <= (l+r)>>1);
        if (k <= ans) {x1 = z[x1].lc; x2 = z[x2].lc; x3 = z[x3].lc;r = (l+r)>>1;}
        else {k -= ans; x1 = z[x1].rc; x2 = z[x2].rc; x3 = z[x3].rc; l = ((l+r)>>1)+1;}
    }
    return l;
}

struct Edge_Node {int y, next;};

int dfn[V*2], pos[V], dep[V*2], f[V*2][30];
int edge_num, vnum, c2[33];
Edge_Node e[V+E];

inline int calc_min(int p, int q) {
    return dep[pos[p]] < dep[pos[q]] ? p : q;
}

inline void init(int n) {
    edge_num = n | 1; vnum = 0;
    kep(i, edge_num) e[i].next = 0;
    c2[0] = 1; kep(i, 30) c2[i] = c2[i-1]*2;
}

inline void link(int x, int y) {
    edge_num++; e[edge_num].y = y;
    e[edge_num].next = e[x].next; e[x].next = edge_num;
    edge_num++; e[edge_num].y = x;
    e[edge_num].next = e[y].next; e[y].next = edge_num;
}
void dfs(int x, int la, int depth) {
    dfn[++vnum] = x; pos[x] = vnum; dep[vnum] = depth;
    T[x] = ++node_num;
    z[T[x]] = z[T[la]];
    insert(T[x], 1, maxint, d[x]);
    for (int p = e[x].next; p; p = e[p].next) {
        if (e[p].y == la) continue;
        dfs(e[p].y, x, depth+1);
        dfn[++vnum] = x; dep[vnum] = depth;
    }
}
inline void make(int n) {
    n <<= 1;
    kep(i, n-1) f[i][0] = dfn[i];
    kep(j, 20) kep(i, n-1) if (i+c2[j] <= n)
        f[i][j] = calc_min(f[i][j-1], f[i+c2[j-1]][j-1]);
}
inline int query(int p, int q) {
    p = pos[p], q = pos[q]; if (p > q) swap(p, q);
    int k = (int)log2(q-p+1);
    return calc_min(f[p][k], f[q-c2[k]+1][k]);
}

int x, y, k, _;

int main(){
    freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    scanf("%d%d", &n, &m);
    init(n); Chmtree_init();
    kep(i, n) scanf("%d", d + i);
    rep(i, n-1) {scanf("%d%d", &x, &y); link(x, y);}
    dfs(1, 0, 0); make(n);
    rep(i, m) {
        scanf("%d%d%d", &x, &y, &k);_ = query(x, y);
        printf("%d\n", ques(T[x], T[y], T[_], d[_], 1, maxint, k));
    }
    return 0;
}
