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


class TheOlympiadInInformatics {
public:
	int find(vector <int> sums, int k) {
		int l = 0, r = 0x7fffffff / 2, ans = 0x7fffffff;
		for (; l <= r;) {
			int tmp = 0, mid = (l+r) / 2;
			for (int i = 0; i < sums.size(); i++)
				tmp += sums[i] / (mid + 1);
			if (tmp > k) l = mid + 1;
			else {
				r = mid - 1;
				ans = mid;
			}
		}
		return ans;
	}
};

