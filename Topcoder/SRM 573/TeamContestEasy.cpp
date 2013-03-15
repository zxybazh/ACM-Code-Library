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

bool u[11111];

class TeamContestEasy {
public:
	int worstRank(vector <int> strength) {
		int tmp = strength[0] + strength[1] + strength[2] - min(strength[0], min(strength[1], strength[2]));
		int n = strength.size(), ans = 1;
		sort(strength.begin() + 3, strength.end());
		memset(u, 0, sizeof(u)); u[0] = u[1] = u[2] = true;
		for (int i = 0; i < n/3-1; i++) {
            int l, r;
            l = n-1;
			for (int j = n-1; j>=3; j--)
                if (!u[j]) {l = j; break;}
            if (u[l]) break;
            u[l] = true;
            r = 0;
            for (int j = 3; j <n; j++)
                if (!u[j] && strength[l] + strength[j] > tmp) {r = j; break;}
            if (u[r] || strength[l] + strength[r] <= tmp) break;
            u[l]= true; u[r]= true;
            for (int j = 3; j <n; j++)
                if (!u[j]) {l = j; break;}
            u[l] = true;
            ans++;
		}
		return ans;
	}
};
