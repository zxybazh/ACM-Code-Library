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
int b[1111][1111], a[1111];

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n);
    for (int i = 1; i <= n; i++)
        for (int j = 1; j <= n; j++)
            re(b[i][j]);
    if (n == 2) a[1] = a[2] = 1;
    else {
        int x = b[1][3] - b[1][2];
        int y = b[2][3];
        int a2 = (y-x) / 2;
        for (int i = 1; i <=n; i++) {
            if (i == 2) a[i] = a2;
            else a[i] = b[2][i] - a2;
        }
    }
    for (int i = 1; i < n; i++) {wt(a[i]);printf(" ");}
    wl(a[n]);
    return 0;
}
