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
#define typee TheKnights
#define function find

class TheKnights {
public:
	double conquered_by_one(int n, int a, int b) {
		int dx[] = {0, a, -a,  a, -a, b,  b, -b, -b};
		int dy[] = {0, b,  b, -b, -b, a, -a,  a, -a};
		int minx, miny, maxx, maxy;
		double P = 1.0 / (double)n / (double)n;
		double ans = 0;
		for (int i = 0; i < (a==b?5:9); i++) {
			minx = max(0, 0-dx[i]);
			miny = max(0, 0-dy[i]);
			maxx = min(n-1, n-1-dx[i]);
			maxy = min(n-1, n-1-dy[i]);;
			ans += P * (maxx >= minx ? maxx - minx + 1: 0) * (maxy >= miny ? maxy - miny + 1: 0);
		}
		return ans;
	}
	double conquered_by_two(int n, int a, int b) {
		int dx[] = {0, a, -a,  a, -a, b,  b, -b, -b};
		int dy[] = {0, b,  b, -b, -b, a, -a,  a, -a};
		int minx, miny, maxx, maxy;
		double P = 1 / (n*(double)n*(n*(double)n-1)/(double)2);
		double ans = 0;
		for (int i = 0; i < (a == b?5:9); i++)
		for (int j = i+1; j < (a == b?5:9); j++)
		{
			minx = max(max(0, 0-dx[i]), 0-dx[j]);
			miny = max(max(0, 0-dy[i]), 0-dy[j]);
			maxx = min(min(n-1, n-1-dx[i]), n-1-dx[j]);
			maxy = min(min(n-1, n-1-dy[i]), n-1-dy[j]);
			ans += P * (maxx >= minx ? maxx - minx + 1: 0) * (maxy >= miny ? maxy - miny + 1: 0);
		}
		return ans;
	}
	double find(int n, int a, int b) {
		return conquered_by_one(n, a, b) * 2 - conquered_by_two(n, a, b);
	}
};
