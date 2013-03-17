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

set< map< pair<char, char> , int> > q;
map< pair<char, char > , int> qq;

class EllysReversals {
public:
	void make(string s) {
		for (int i = 0; i < s.size(); i+= 2) {
			char a = s[i];
			char b = i +1 < s.size()? s[i+1]:' ';
			if (a > b) swap(a, b);
			qq[make_pair(a,b)]++;
		}
	}
	int getMin(vector <string> words) {
		int n = words.size();  q.clear();
		for (int i = 0; i < n; i++) {
			qq.clear();
			make(words[i]);
			if (q.find(qq) != q.end()) q.erase(qq); else q.insert(qq);
		}
		return q.size();
	}
};
