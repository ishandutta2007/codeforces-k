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
int main() {
#define int long long
	iostream::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	REP(tea, test_case) {
		int n;
		cin >> n;
		vector<pair<long long, long long>> inputs;
		REP(i, n) {
			int a, b;
			cin >> a >> b;
			inputs.push_back(make_pair(a, b));
		}
		sort(inputs.begin(), inputs.end());
		priority_queue<long long> go;
		long long ans = 0;
		long long pump = n-1;
		for (int i = inputs.size() - 1; i >= 0; --i) {
			go.push(-inputs[i].second);
			while (pump < inputs[i].first) {
				ans += go.top() * -1LL;
				go.pop();
				pump++;
			}
			pump--;
		}
		cout << ans << endl;
	}
}