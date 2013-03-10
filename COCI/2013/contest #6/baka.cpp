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

int n, m, l;
char a[1111];
int b[1111], c[1111];

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    gets(a); l = strlen(a);
    b[1] = 2;
    for (int i = 2; i < 11; i++) b[i] = b[i-1] + 1;
    for (int i = 'A'; i <= 'C'; i++) c[i] = 2;
    for (int i = 'D'; i <= 'F'; i++) c[i] = 3;
    for (int i = 'G'; i <= 'I'; i++) c[i] = 4;
    for (int i = 'J'; i <= 'L'; i++) c[i] = 5;
    for (int i = 'M'; i <= 'O'; i++) c[i] = 6;
    for (int i = 'P'; i <= 'S'; i++) c[i] = 7;
    for (int i = 'T'; i <= 'V'; i++) c[i] = 8;
    for (int i = 'W'; i <= 'Z'; i++) c[i] = 9;
    int ans = 0;
    for (int i = 0; i < l; i++) ans += b[c[a[i]]];
    wl(ans);
    return 0;
}
