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
#define N 1111111

int n, m, x, y;
int f[2][N];

int lbt(int x) {
    return (-x) & x;
}

void add(int p, int x, int d) {
    for (; x < N; x += lbt(x)) f[p][x] += d;
}

void cover(int p, int x, int y) {
    add(p, x , 1);
    add(p, y+1, -1);
}

int ques(int p, int x) {
    int ans = 0;
    for (; x > 0; x -= lbt(x)) ans += f[p][x];
    return ans;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n);
    int oo = 1 << 30;
    for (int i = 0; i < n; i++) {
        int minx(oo), miny(oo), maxx(-oo), maxy(-oo);
        for (int j = 0; j < 3; j++) {
            re2(x, y); x++; y++;
            minx = min(minx, x); maxx = max(maxx, x);
            miny = min(miny, y); maxy = max(maxy, y);
        }
        cover(0, minx + 1, maxx -1);
        cover(1, miny + 1, maxy -1);
    }
    scanf("%d\n", &m); char c1; int k;
    for (int i = 0; i < m; i++) {
        scanf("%c = %d\n", &c1, &k);
        k++;
        wl(ques(c1 == 'y', k));
    }
    return 0;
}
