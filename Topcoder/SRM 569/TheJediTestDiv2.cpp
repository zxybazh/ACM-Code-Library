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


class TheJediTestDiv2 {
public:
	int countSupervisors(vector <int> students, int Y, int J) {
		int n = students.size();
		int ans = 2147483647 / 2;
		for (int i = 0; i < n; i++) {
			int tmp = 0;
			for (int j = 0; j < n; j++) {
				if (i == j) tmp += (students[i] - Y >= 0 ? ((students[i] - Y) % J ? (students[i] - Y) / J + 1 : (students[i] - Y) / J) : 0);
				else tmp += students[j] % J ? students[j] / J + 1: students[j] / J;
			}
			if (tmp < ans) ans = tmp;
		}
		return ans;
	}
};
