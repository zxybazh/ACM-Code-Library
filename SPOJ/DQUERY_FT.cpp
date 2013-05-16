#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
template <class T> inline T _lbt(T a) {return (a&(a^(a-1)));}

/*****Fenwick Tree Module**************************/

#define Fenwick_Tree_Size 1010101

class Fenwick_Tree {
    private:
        static int f[Fenwick_Tree_Size];
        static int size;
    public:
        static inline void setsize(int x) {size = x;}
        static inline void add(int x, int d) {
            for (;x <= size; x+= _lbt(x)) f[x] += d;
        }
        static inline int ques(int x) {
            int ans = 0; for (;x > 0; x-= _lbt(x)) ans += f[x]; return ans;
        }
};

int Fenwick_Tree::f[Fenwick_Tree_Size], Fenwick_Tree::size;

/*****End line of Fenwick Tree by zxybazh**********/

#define N 30303
#define M 202020

int n, m, t, a[N], num, la[1010101], ans[M];
class Triple{public: int a[3];} b[M];

inline bool cmp(Triple a, Triple b) {return a.a[1] < b.a[1];}

inline void Solution_Production() {
    scanf("%d", &n); Fenwick_Tree::setsize(n);
    kep(i, n) scanf("%d", a+i); scanf("%d", &m);
    rep(i, m) {scanf("%d%d", &b[i].a[0], &b[i].a[1]); b[i].a[2] = i;}
    sort(b, b+m, cmp); t = 0;
    kep(i, n) {
        if (!la[a[i]]) num++;
        if (la[a[i]]) Fenwick_Tree::add(la[a[i]], -1);
        Fenwick_Tree::add((la[a[i]] = i), 1);
        while (t < m && b[t].a[1] == i) {
            ans[b[t].a[2]] = num - Fenwick_Tree::ques(b[t].a[0]-1); t++;
        }
    }
    rep(i, m) printf("%d\n", ans[i]);
}

int main() {
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    Solution_Production();
    return 0;
}
