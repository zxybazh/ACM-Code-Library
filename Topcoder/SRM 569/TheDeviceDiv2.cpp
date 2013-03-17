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


class TheDeviceDiv2 {
public:
    int k[55][2];
	string identify(vector <string> plates) {
	    int n = plates.size();
	    int m = plates[0].length();
		memset(k, 0, sizeof(k));
	    for (int i = 0; i < n; i++)
	        for (int j = 0; j < m; j++)
                k[j][plates[i][j] - '0']++;
        for (int i = 0; i < m; i++)
            if (k[i][0] < 1 || k[i][1] < 2) return "NO";
        return "YES";
	}
};
