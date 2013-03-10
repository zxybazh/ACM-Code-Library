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

int n, m;
int a[111111];
bool *mmap, hash[666666];

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n); mmap = & hash[333333];
    memset(hash, 0, sizeof(hash));
    for (int i = 0; i < n; i++) re(a[i]);
    int ans = 0;
    for (int i = 0; i < n; i++) {
        bool flag = false;
        for (int j = 0; j < i; j++) if (mmap[a[i] - a[j]]) {flag = true; break;}
        for (int j = 0; j < i; j++) mmap[a[i] + a[j]] = true;
        mmap[a[i]+a[i]] = true;
        ans += flag;
    }
    wl(ans);
    return 0;
}
