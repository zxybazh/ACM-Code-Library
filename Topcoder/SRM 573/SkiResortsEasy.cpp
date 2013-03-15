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

class SkiResortsEasy {
public:
	int minCost(vector <int> altitude) {
		int maxn = 0x7fffffff / 2;
		int ans = 0;
		for (int i = 0; i < altitude.size(); i++) {
			if (maxn >= altitude[i]) maxn = altitude[i];
			else ans += altitude[i] - maxn;
		}
		return ans;
	}
};
