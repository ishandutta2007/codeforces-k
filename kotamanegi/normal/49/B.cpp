#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144
#define REP(a,b) for(long long a = 0;a < b;++a)
int main() {
	string a, b;
	cin >> a >> b;
	int now_max = 0;
	for (int i = 0; i < a.length(); ++i) {
		now_max = max(now_max, a[i] - '0');
	}
	for (int i = 0; i < b.length(); ++i) {
		now_max = max(now_max, b[i] - '0');
	}
	now_max++;
	int now_itr = 0;
	int ans = 0;
	for (int i = 0;a.empty() == false||b.empty() == false; ++i) {
		if (a.empty() == false) {
			now_itr += a.back() - '0';
			a.pop_back();
		}
		if (b.empty() == false) {
			now_itr += b.back() - '0';
			b.pop_back();
		}
		now_itr /= now_max;
		ans++;
	}
	if (now_itr != 0)ans++;
	cout << ans << endl;
}