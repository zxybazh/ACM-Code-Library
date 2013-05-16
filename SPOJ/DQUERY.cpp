#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
#define N 30303
int n, m, k, t, x, y, p, la[1010101], sum[N], st[111];
struct Chmnode {int lc, rc, sum;};
#define Chmsize 30303*16*2

struct Chmtree {
        int root;
        static int node_num;
        static Chmnode z[Chmsize];
        static inline int ask(int x) {
            z[++node_num] = z[x]; return node_num;
        }
        static inline void init(){
            node_num = z[0].lc = z[0].rc = z[0].sum = 0;
        }
        static inline void add(int x, int l, int r, int p, int d) {
            t = 1; st[t] = x;
            while (l < r) {
                if (p <= (l+r)/2) {
                    x = (z[x].lc = ask(z[x].lc)); r = (l+r)/2;
                } else {
                    x = (z[x].rc = ask(z[x].rc)); l = (l+r)/2+1;
                }
                st[++t] = x;
            }
            kep(i, t) z[st[i]].sum+=d;
        }
        static int query(int x, int ll, int rr, int l, int r) {
            if (l <= ll && rr <= r) return z[x].sum;
            else {
                int ans = 0;
                if (l <= (ll+rr)/2) ans += query(z[x].lc, ll, (ll+rr)/2, l, r);
                if (r >  (ll+rr)/2) ans += query(z[x].rc, (ll+rr)/2+1, rr, l, r);
                return ans;
            }
        }
} T[N];

int Chmtree::node_num;
Chmnode Chmtree::z[Chmsize];

inline void Solution_Production() {
    Chmtree::init();
    scanf("%d", &n);
    kep(i, n) {
        scanf("%d", &x);
        sum[i] = sum[i-1]; if (!la[x]) sum[i]++;
        T[i].root = Chmtree::ask(T[i-1].root);
        if (la[x]) Chmtree::add(T[i].root, 1, 32767, la[x], -1);
        Chmtree::add(T[i].root, 1, 32767, i, 1);
        la[x] = i;
    }
    scanf("%d", &m);
    rep(i, m) {
        scanf("%d%d", &x, &y);
        printf("%d\n", sum[y] - (x-1?Chmtree::query(T[y].root, 1, 32767, 1, x-1):0));
    }
}

int main(){
    freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    Solution_Production();
    return 0;
}

