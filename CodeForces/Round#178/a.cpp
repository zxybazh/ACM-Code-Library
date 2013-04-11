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
#define N 111

int n, m, k, t, p, a[N], x, y;

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n); for (int i = 1; i <= n; i++) re(a[i]);
    re(m); while (m--) {
        re2(x, y);
        a[x+1] += a[x] - y;
        a[x-1] += y-1;
        a[x] = 0;
    }
    for (int i = 1; i <= n; i++) wl(a[i]);
    return 0;
}

