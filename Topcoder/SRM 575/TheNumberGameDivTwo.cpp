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
#include <cstring>

using namespace std;

bool lose[11111];

class TheNumberGameDivTwo {
public:
	bool check(int n) {
		for (int i = 2; i < n; i++)
		if (n % i == 0 && lose[n-i]) return 0;
		return 1;
	}
	string find(int n) {
		string ans[2];
		ans[0] = "John";
		ans[1] = "Brus";
		memset(lose, 0, sizeof(lose));
		lose[1] = true; lose[2] = true;
		for (int i = 3; i <= n; i++)
			lose[i] = check(i);
		return ans[lose[n]];
	}
};
