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

using namespace std;


class EllysFigurines {
public:
	int getMoves(vector <string> board, int R, int C) {
		int n = board.size();
		int m = board[0].size();
		int ans = 0x7fffffff;
		for (int i = 0; i < (1 << n); i++) {
			int t = 0, k = 0, tmp = 0;
			for (int j = 0; j < n; j++) {
				if (i & (1 << j)) k++;
				if (k) t++;
				if (t == R) {tmp++; k = 0; t = 0;}
			}
			if (k) {tmp++; t = 0; k = 0;}
			for (int j = 0; j < m; j++) {
				bool flag = false;
				for (int p = 0; p < n; p++)
					if (!((1 << p) & i)){
						flag |= board[p][j] == 'X';
					}
				if (flag) k++;
				if (k) t++;
				if (t == C) {tmp++; k = 0; t = 0;}
			}
			if (k) tmp++;
			if (tmp < ans) ans = tmp;
		}
		return ans;
	}
};
