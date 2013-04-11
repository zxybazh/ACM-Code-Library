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

int n1, n2, n, m, s1[N], s2[N], x, y;
struct node {
    int t, w;
} a1[N], a2[N];

bool cmp(node a, node b) {
    return (a.w < b.w);
}

bool check(int d) {
    for (int i = 0; i <= min(d, n1); i++)
        if ((d- i) % 2 == 0 && (d-i)/2 <= n2) {
            if (s1[n1-i]+s2[n2-(d-i)/2] <= d) return true;
        }
    return false;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    re(n); n1 = 0; n2 = 0;
    for (int i = 0; i < n; i++) {
        re2(x, y);
        if (x == 1) { a1[++n1].t = x; a1[n1].w = y;}
        else { a2[++n2].t = x; a2[n2].w = y;}
    }
    sort(&a1[1], &a1[1] + n1, cmp);
    sort(&a2[1], &a2[1] + n2, cmp);
    s1[0] = 0; for (int i = 1; i <= n1; i++) s1[i] = s1[i-1] + a1[i].w;
    s2[0] = 0; for (int i = 1; i <= n2; i++) s2[i] = s2[i-1] + a2[i].w;
    for (int i = 0; i <= n1+n2*2; i++)
        if (check(i)) {cout << i << endl; break;}
    return 0;
}

