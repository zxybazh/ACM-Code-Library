#include <vector>
#include <list>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <stack>
#include <bitset>
#include <algorithm>
#include <functional>
#include <numeric>
#include <utility>
#include <sstream>
#include <iostream>
#include <iomanip>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <utility>
#include <cstring>
#define LL long long
#define fo(i, l, r) for (int i = l; i < r; i++)
#define MP make_pair
#define data pair<int, int>
using namespace std;

int gcd(int x, int y){
	if (!y) return x;
	return gcd(y, x % y);
}

class KnightCircuit {
public:
	long long bfs(int w, int h, int a, int b){
		queue< data > q;
		bool ma[22][111111];
		const int dx[8] = {a, a, -a, -a, b, b, -b, -b};
		const int dy[8] = {b, -b, b, -b, a, -a, a, -a};
        int best = 0;
		memset(ma, 0, sizeof(ma));
        data tmp;
        fo(i, 0, w)
            fo(j, 0, h)
                if (!ma[i][j]){
                    q.push(MP(i, j));
                    ma[i][j] = 1;
                    int ans = 1;

                    //out << i << " " << j << endl;

                    while (!q.empty()){
                    tmp = q.front();
                    fo(i, 0, 8){
                        int x = tmp.first + dx[i];
                        int y = tmp.second + dy[i];
                        if (x >= 0 &&  x < w && y >= 0 && y < h && !ma[x][y]){

                            //out << x << " " << y << endl;

                            ma[x][y] = 1;
                            q.push(MP(x, y));
                            ans++;
                        }
                    }
                    q.pop();
                }
                //cout << "**********************" << endl;
                best = max(ans, best);
            }
        return best;
	}
	long long maxSize(int w, int h, int a, int b) {
		int tmp = gcd(a, b);
		if (tmp != 1)
			return maxSize((w - 1) / tmp + 1, (h - 1) / tmp + 1, a / tmp, b / tmp);
		if (w > h) swap(w, h);
		if (w <= 20) return bfs(w, h, a, b);
		if ((a & 1) && (b & 1)) return ((LL) w * (LL) h + (LL)1) / 2;
		return (LL) w * (LL) h;
	}
};
