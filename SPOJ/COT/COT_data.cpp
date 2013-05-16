#include <algorithm>
#include <iostream>
#include <cstring>
#include <sstream>
#include <cstdlib>
#include <utility>
#include <numeric>
#include <cstdio>
#include <string>
#include <vector>
#include <bitset>
#include <cmath>
#include <queue>
#include <stack>
#include <ctime>
#include <map>
#include <set>
using namespace std;
typedef pair<int, int> PII;
typedef vector<string> VS;
typedef map<int, int> MII;
typedef vector<PII> VPII;
typedef vector<int> VI;
typedef set<int> SI;
typedef long double LD;
typedef long long LL;
#define PB push_back
#define MP make_pair
#define SE second
#define FI first
const int inf = 1073741823;
const int maxint = 0x7fffffff;
const LL  INF = 1152921504606846976ll;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
template <class T> T _sqr(T a) {return (a*a);}
template <class T> T _abs(T a) {return (a>=0?a:-a);}
template <class T> T _lbt(T a) {return (a&(a^(a-1)));}
template <class T> T _max(T a, T b) {return (a>b?a:b);}
template <class T> T _min(T a, T b) {return (a<b?a:b);}
template <class T> T _smax(T a, T b, T c) {return _max(_max(a,b),c);}
template <class T> T _smin(T a, T b, T c) {return _min(_min(a,b),c);}
template <class T> T _sqrt(T a) {T b,c;for(b = sqrt(a),c=b-2;c<=b+2;c++)if(_sqr(c)<=a)b=c;return b;}

int n, m, k, t, x, y, p, T, a[101010];

int find(int k) {
    return a[k] == k ? k : (a[k] = find(a[k]));
}

/*****LCA-RMQ**************************************/

struct Edge_Node {int y, next;};

#define E 101010*2
#define V 101010

class LCA_RMQ {
    public:
        static int dfn[V*2], pos[V], dep[V*2], f[V*2][30];
        static int edge_num, vnum, c2[33];
        static Edge_Node e[V+E];
        static int calc_min(int p, int q) {
            return dep[pos[p]] < dep[pos[q]] ? p : q;
        }
        static void init(int n) {
            edge_num = n | 1; vnum = 0;
            kep(i, edge_num) e[i].next = 0;
            c2[0] = 1; kep(i, 30) c2[i] = c2[i-1]*2;
        }
        static void link(int x, int y) {
            edge_num++; e[edge_num].y = y;
            e[edge_num].next = e[x].next; e[x].next = edge_num;
            edge_num++; e[edge_num].y = x;
            e[edge_num].next = e[y].next; e[y].next = edge_num;
        }
        static void dfs(int x, int la, int depth) {
            dfn[++vnum] = x; pos[x] = vnum; dep[vnum] = depth;
            for (int p = e[x].next; p; p = e[p].next) {
                if (e[p].y == la) continue;
                dfs(e[p].y, x, depth+1);
                dfn[++vnum] = x; dep[vnum] = depth;
            }
        }
        static void make(int n) {
            kep(i, n*2-1) f[i][0] = dfn[i];
            kep(j, 20) kep(i, n*2-1) if (i+c2[j] <= n*2)
                f[i][j] = calc_min(f[i][j-1], f[i+c2[j-1]][j-1]);
        }
        static int ques(int p, int q) {
            p = pos[p], q = pos[q]; if (p > q) swap(p, q);
            int k = (int)log2(q-p+1);
            return calc_min(f[p][k], f[q-c2[k]+1][k]);
        }
};

int LCA_RMQ::dfn[V*2], LCA_RMQ::pos[V],
    LCA_RMQ::dep[V*2], LCA_RMQ::f[V*2][30];
int LCA_RMQ::edge_num, LCA_RMQ::vnum, LCA_RMQ::c2[33];
Edge_Node LCA_RMQ::e[V+E];

/*****End Line Of LCA_RMQ by zxybazh****************/

void Solution_Production() {
    n = m = 100000;
    kep(i, n) a[i] = i;
    cout << n << " " << m << endl;
    rep(i, n-1) cout << rand() % maxint+1 << " ";
    cout << rand() % maxint+1 << endl;
    LCA_RMQ::init(n);
    for (int i = 1; i < n; i++) {
        x = rand() % n + 1;
        y = rand() % n + 1;
        while (find(x) == find(y)) {
            x = rand() % n + 1;
            y = rand() % n + 1;
        }a[find(x)] = find(y);
        cout << x << " " << y << endl;
        LCA_RMQ::link(x, y);
    }
    LCA_RMQ::dfs(1, 0, 0);
    LCA_RMQ::make(n);
    rep(i, m) {
        x = rand() % n + 1;
        y = rand() % n + 1;
        t = LCA_RMQ::ques(x, y);
        k = LCA_RMQ::dep[LCA_RMQ::pos[x]] - 2*LCA_RMQ::dep[LCA_RMQ::pos[t]] + LCA_RMQ::dep[LCA_RMQ::pos[y]] + 1;
        cout << x << " " << y << " " << rand() % k + 1 << endl;
    }
}

int main(){
    srand(time(0));
    freopen("in.txt", "w", stdout);
    Solution_Production();
    return 0;
}

