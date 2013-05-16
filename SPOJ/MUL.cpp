#include <algorithm>
#include <iostream>
#include <cstdio>
#include <complex>
#include <cstring>
using namespace std;
typedef long double LD;
typedef long long LL;
const LD  pi = acos(-1);
typedef complex<LD> CPD;
template <class T> inline T _pow(T a, T b) {T ans = 1; for (;b;b>>=1, a*=a) if (b & 1) ans *= a; return ans;}
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
#define ifo(i, l, r) for (int i = l; i <= r; i++)
#define dfo(i, r, l) for (int i = r; i >= l; i--)
#define N 33030

class FFT {
    private:
        static int c2[33];
        static LL base;
        static int  bit_rev(int k, int n) {
            int ans = 0;
            rep(i, n) {if (c2[i] & k) ans |= c2[n-i-1];}
            return ans;
        }
        static void work(CPD A[], int n, int tt) {
            int t = log2(n), m = 1;
            kep(s, t) {
                m <<= 1;
                CPD wm(cos(2 * pi / m), tt*sin(2 * pi / m));
                for (int k = 0; k < n; k += m) {
                    CPD w(1);
                    rep(j, m / 2) {
                        CPD t = w * A[k + j + m / 2];
                        CPD u = A[k + j];
                        A[k + j] = u + t;
                        A[k + j + m / 2] = u - t;
                        w = w * wm;
                    }
                }
            }
        }
        static void DFT(int a[], CPD A[], int n) {
            int t = log2(n);
            rep(i, n) A[i] = a[bit_rev(i, t)];
            work(A, n, 1);
        }
        static CPD ta[N], tb[N];
        static int DFT_back(CPD A[], int a[], int n) {
            int t = log2(n);
            rep(i, n) tb[i] = A[bit_rev(i, t)];
            work(tb, n, -1);
            rep(i, n) tb[i] /= n; tb[n] = 0; LL tmp;
            rep(i, n) {
                tmp = round(tb[i].real());
                tb[i+1] += tmp /base;
                a[i] = tmp % base;
            }
            /*impossible to exceed n bits*/
            while (n > 0 && !a[n-1]) --n;
            return n;
        }
    public:
    static void set_base(LL x) {base = x;}
    static int solve(int a[], int b[], int c[], int n) {
        c2[0] = 1; kep(i, 30) c2[i] = c2[i-1] * 2;
        DFT(a, ta, n);
        DFT(b, tb, n);
        rep(i, n) ta[i] *= tb[i];
        return DFT_back(ta, c, n);
    }
};

CPD FFT::ta[N], FFT::tb[N];
LL FFT::base;
int FFT::c2[33];

/***************FFT End Line****************/
int n, m, l, a[N], b[N], c[N], T;
char d[N];

void Solution_Production() {
    memset(a, 0, sizeof(a));
    memset(b, 0, sizeof(b));
    int i;
    for (m = -1; m < 0 || d[m] != ' ';) d[++m] = getchar();
    for (i = m-1; i >= 0; i--) a[i/5] = a[i/5]*10 + d[m-i-1]-'0';
    m = (m-1)/5 + 1;
    gets(d), l = strlen(d);
    for (i = l-1; i >= 0; i--) b[i/5] = b[i/5]*10 + d[l-i-1]-'0';
    l = (l-1)/5 + 1;

    n = _pow(2, (int)ceil(log2(l + m)));
    n = FFT::solve(a, b, c, n);
    if (!n) puts("0"); else {
        printf("%d", c[n-1]);
        dfo(i, n-2, 0) printf("%05d", c[i]);
        puts("");
    };
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    FFT::set_base(100000ll);
    scanf("%d\n", &T);
    while (T--) Solution_Production();
    return 0;
}



