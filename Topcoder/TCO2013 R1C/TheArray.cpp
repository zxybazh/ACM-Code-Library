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


class TheArray {
public:
	int find(int n, int d, int first, int last) {
		int ans = max(first, last);
		for (int i = 2; i < n; i++) {
			int maxn = first + d * (i - 1);
			if (abs(maxn - last) > d * (n - i)) continue;
			ans = max(maxn, ans);
		}
		swap(first, last);
		for (int i = 2; i < n; i++) {
			int maxn = first + d * (i - 1);
			if (abs(maxn - last) > d * (n - i)) continue;
			ans = max(maxn, ans);
		}
		return ans;
	}
};
