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
#define typee DirectionBoard
#define function getMinimum
#define N 555
#define M (N*15)

struct node{
	int n, y, f, c;
}e[M];
const int oo = 0x7fffffff / 2;
int dist[N], des, det, n, pre[N], ans, vis[N], fro[N];
int q[N*N], ff, rr, nume;

class DirectionBoard {
public:
	void fill(int x[], int y) {
		for (int i = 0; i < N; i++) x[i] = y;
	}
	bool spfa(){
		fill(dist, oo); dist[des] = 0; fill(vis , 0);
		vis[des] = 1; ff = 1; rr = 1; q[1] = des;
		while (ff <= rr) {
			int k = q[ff++];
			for (int p = e[k].n; p; p = e[p].n)
				if (e[p].f && dist[k] + e[p].c < dist[e[p].y]){
					int t = e[p].y;
					dist[t] = dist[k] + e[p].c;
					pre[t] = p; fro[t] = k;
					if (!vis[t]) {q[++rr] = t; vis[t] = rr;}
					if (dist[t] < dist[q[ff]]) {
						vis[q[ff]] = vis[t]; swap(q[ff], q[vis[t]]); vis[t] = ff;
					}
				}
			vis[k] = 0;
		}
		return (dist[det] != oo);
	}
	void expand() {
		int flow = oo;
		for (int k = det; k != des; k = fro[k])
			flow = min(flow, e[pre[k]].f);
		for (int k = det; k != des; k = fro[k]) {
			e[pre[k]].f -= flow;
			e[pre[k]^1].f += flow;
			ans += flow*e[pre[k]].c;
		}
	}
    void link(int x, int y, int f, int d) {
		nume++;
        e[nume].n = e[x].n;e[x].n = nume;
		e[nume].y = y;e[nume].f = f;e[nume].c =  d;
        nume++;
		e[nume].n = e[y].n;e[y].n = nume;
		e[nume].y = x;e[nume].f = 0;e[nume].c = -d;

    }
	int getMinimum(vector <string> board) {
		int tn = board.size(); int tm = board[0].size();
		n = tn * tm; memset(e, 0, sizeof(e));
		des = n*2; det = n*2+ 1; nume = n*2+1;
		//if (!(nume & 1)) nume++;
	    for (int i = 0; i < n; i++) {
	        link(des, n+i, 1, 0);
	        link(i  , det, 1, 0);
	    }
	    for (int i = 0; i < tn; i++)
            for (int j = 0; j < tm; j++) {
                link(i * tm + j + n, (i * tm + (j + tm + 1) % tm), 1, board[i][j] != 'R');
                link(i * tm + j + n, (i * tm + (j + tm - 1) % tm), 1, board[i][j] != 'L');
                link(i * tm + j + n,   (i + tn - 1) % tn * tm + j, 1, board[i][j] != 'U');
                link(i * tm + j + n,   (i + tn + 1) % tn * tm + j, 1, board[i][j] != 'D');
            }
		ans = 0;
        while (spfa()) expand();
		return ans;
	}
};
