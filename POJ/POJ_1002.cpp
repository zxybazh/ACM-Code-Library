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

int n;
map<char, char> dict;
map<string, int> book;
string s, t;

void Solution_Production() {
    cin >> n;
    dict['A'] = dict['B'] = dict['C'] = '2';
    dict['D'] = dict['E'] = dict['F'] = '3';
    dict['G'] = dict['H'] = dict['I'] = '4';
    dict['J'] = dict['K'] = dict['L'] = '5';
    dict['M'] = dict['N'] = dict['O'] = '6';
    dict['P'] = dict['R'] = dict['S'] = '7';
    dict['T'] = dict['U'] = dict['V'] = '8';
    dict['W'] = dict['X'] = dict['Y'] = '9';
    rep(i, n) {
        cin >> t;
        s.clear();
        rep(j, t.length()) {
            if (t[j] == '-') continue;
            if (dict[t[j]]) s.PB(dict[t[j]]);
            else s.PB(t[j]);
        }
        s.insert(3, "-");
        book[s]++;
    }
    bool flag = false;
    for (map<string, int>::iterator p = book.begin(); p != book.end(); p++)
        if (p->SE > 1) {
            flag = true;
            cout << p->FI << " " << p->SE << endl;
        }
    if (!flag) cout << "No duplicates. " << endl;
}

int main(){
    //freopen("in.txt", "r", stdin);
    //freopen("ou.txt", "w", stdout);
    ios::sync_with_stdio(0);
    Solution_Production();
    return 0;
}

