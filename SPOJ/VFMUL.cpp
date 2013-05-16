#include <algorithm>
#include <iostream>
#include <cstdio>
#include <complex>
#include <cstring>
using namespace std;
typedef long double LD;
typedef long long LL;
typedef unsigned int uint;
const LD  pi = acos(-1);
typedef complex<LD> CPD;
#define rep(i, n) for (int i = 0; i < n; i++)
#define kep(i, n) for (int i = 1; i<= n; i++)
#define ifo(i, l, r) for (int i = l; i <= r; i++)
#define dfo(i, r, l) for (int i = r; i >= l; i--)
#define N 150505

class FFT {
    private:
        static uint rev(uint a){
            a=((a&0x55555555U)<<1)|((a&0xAAAAAAAAU)>>1);
            a=((a&0x33333333U)<<2)|((a&0xCCCCCCCCU)>>2);
            a=((a&0x0F0F0F0FU)<<4)|((a&0xF0F0F0F0U)>>4);
            a=((a&0x00FF00FFU)<<8)|((a&0xFF00FF00U)>>8);
            a=((a&0x0000FFFFU)<<16)|((a&0xFFFF0000U)>>16);
            return a;
        }
        static int c2[33];
        static LL base;
        /*static int  bit_rev(int k, int n) {
            int ans = 0;
            rep(i, n) {if (c2[i] & k) ans |= c2[n-i-1];}
            return ans;
        }*/
        static void work(CPD A[], int n, int t, int tt) {
            int m = 1; CPD w;
            kep(s, t) {
                m <<= 1;
                CPD wm(cos(2 * pi / m), tt*sin(2 * pi / m));
                for (int k = 0; k < n; k += m) {
                    w = 1;
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
        static void DFT(int a[], CPD A[], int t, int n) {
            rep(i, n) A[i] = a[rev(i)>>(32-t)];
            work(A, n, t, 1);
        }
        static CPD ta[N], tb[N];
        static int DFT_back(CPD A[], int a[], int t, int n) {
            rep(i, n) tb[i] = A[rev(i)>>(32-t)];
            work(tb, n, t, -1);
            LL tmp = 0;
            rep(i, n) {
                tmp += round(tb[i].real()/n);
                a[i] = tmp % base;
                tmp /= base;
            }
            /*impossible to exceed n bits*/
            while (n > 0 && !a[n-1]) --n;
            return n;
        }
    public:
    static void set_base(LL x) {base = x;}
    static int solve(int a[], int b[], int c[], int t) {
        c2[0] = 1; kep(i, 30) c2[i] = c2[i-1] * 2;
        int n = c2[t];
        DFT(a, ta, t, n);
        DFT(b, tb, t, n);
        rep(i, n) ta[i] *= tb[i];
        return DFT_back(ta, c, t, n);
    }
};

CPD FFT::ta[N], FFT::tb[N];
LL FFT::base;
int FFT::c2[33];

/***************FFT End Line****************/
int n, m, l, a[N], b[N], c[N], T;
char d[N*5];

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

    n = FFT::solve(a, b, c, ceil(log2(l + m)));
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



