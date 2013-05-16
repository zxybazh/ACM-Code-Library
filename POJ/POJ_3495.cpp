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
template <class T> inline T _sqr(T a) {return (a*a);}
template <class T> inline T _abs(T a) {return (a>=0?a:-a);}
template <class T> inline T _lbt(T a) {return (a&(a^(a-1)));}
template <class T> inline T _max(T a, T b) {return (a>b?a:b);}
template <class T> inline T _min(T a, T b) {return (a<b?a:b);}
template <class T> inline T _smax(T a, T b, T c) {return _max(_max(a,b),c);}
template <class T> inline T _smin(T a, T b, T c) {return _min(_min(a,b),c);}
template <class T> inline T _sqrt(T a) {T b,c;for(b = sqrt(a),c=b-2;c<=b+2;c++)if(_sqr(c)<=a)b=c;return b;}

LL x, y, z, ans;

LL cn2(LL k) {
    if (k & 1) {
        return (k-1)/2*k;
    } else {
        return k/2*(k-1);
    }
}

LL calc(LL a, LL d, LL n, LL m, LL M) {
    LL ans = 0;
    if (a >= m) ans = (ans + n % M * (a/m) % M) % M;
    if (d >= m) ans = (ans + cn2(n) % M * (d/m) % M) % M;
    a %= m; d %= m;
    if (a + d * (n-1) < m) return ans;
    ans = (ans + calc((a + d * n) % m, m, (a + d * n) / m, d, M)) % M;
    return ans;
}

void Solution_Production() {
    ans = 0;
    for (int i = 0; i < 33; i++) {
        if (calc(x, z, (y-x)/z+1, 1ll << i, 2)) ans += 1ll << i;
    }
    printf("%lld\n", ans);
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    while (scanf("%lld%lld%lld", &x, &y, &z) != EOF)
        Solution_Production();
    return 0;
}

