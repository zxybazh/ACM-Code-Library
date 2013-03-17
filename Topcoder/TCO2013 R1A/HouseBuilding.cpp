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

class HouseBuilding {
public:
	int getMinimum(vector <string> area) {
		int n = area.size();
		int m = area[0].size();
		int ans = 0x7fffffff;
		for (int i = 0; i < 9; i++) {
			int tans = 0;
			for (int j = 0; j < n; j++)
				for (int k = 0; k < m; k++) {
					int val = area[j][k] - '0';
					if (val < i) tans += i - val;
					if (val >i+1) tans += val - i - 1;
				}
			ans = min(tans, ans);
		}
		return ans;
	}
};
