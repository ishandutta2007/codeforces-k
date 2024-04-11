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
long long ruiseki[500000];
int main() {
	int n;
	cin >> n;
	vector<pair<long long,long long>> inputs;
	REP(i, n) {
		long long a;
		cin >> a;
		inputs.push_back(make_pair(a, i+1));
	}
	sort(inputs.begin(), inputs.end());
	int itr = 0;
	long long now = 0;
	long long ans = LONG_INF;
	REP(i, n) {
		ruiseki[i] += inputs[i].first;
		ruiseki[i + 1] = ruiseki[i];
	}
	long long k;
	cin >> k;
	REP(i, k) {
		now += inputs[i].first * (i + 1LL) - ruiseki[i];
	}
	ans = now;
	for (long long i = k; i < n; ++i) {
		now += inputs[i - k].first * k;
		now -= ruiseki[i - 1];
		if (i != k) {
			now += ruiseki[i - k - 1];
		}
		now += inputs[i].first * k;
		now -= ruiseki[i];
		now += ruiseki[i - k];
		if (ans > now) {
			ans = now;
			itr = i - k+1;
		}
	}
	REP(q, k) {
		cout << inputs[q + itr].second << " ";
	}
	cout << endl;
}