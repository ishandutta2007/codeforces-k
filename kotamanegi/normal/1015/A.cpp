//J^!w

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
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int main(){
	int n, m;
	cin >> n >> m;
	vector<pair<int, int>> inputs;
	REP(i, n) {
		int a, b;
		cin >> a >> b;
		inputs.push_back(make_pair(a, b));
	}
	vector<int> ans;
	for (int i = 1; i <= m; ++i) {
		int ok = 1;
		REP(q, n) {
			if (inputs[q].first <= i && i <= inputs[q].second) ok = 0;
		}
		if (ok == 1) ans.push_back(i);
	}
	cout << ans.size() << endl;
	REP(i, ans.size()) {
		cout << ans[i] << " ";
	}
	cout << endl;
}