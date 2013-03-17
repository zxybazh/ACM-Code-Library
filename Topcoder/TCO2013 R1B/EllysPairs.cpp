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


class EllysPairs {
public:
	int getDifference(vector <int> knowledge) {
		sort(knowledge.begin(), knowledge.end());
		int minn = 0x7fffffff;
		int maxn = - minn;
		int n = knowledge.size();
		for (int i = 0; i < knowledge.size(); i++) {
			int val = knowledge[i] + knowledge[n-1-i];
			maxn = max(maxn, val);
			minn = min(minn, val);
		}
		return maxn - minn;
	}
};
