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


class TheSwapsDivTwo {
public:
	int find(vector <int> sequence) {
		int n = sequence.size();
		int ans = 0;
		bool flag = false;
		for (int i = 0; i < n; i++)
			for (int j = i + 1; j < n; j++) {
				if (sequence[i] != sequence[j]) ans++;
				flag |= sequence[i] == sequence[j];
			}
		return ans + flag;
	}
};
