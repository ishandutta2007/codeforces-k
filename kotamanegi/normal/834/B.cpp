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
int cnt[26] = {};
int firstt[26] = {};
int main() {
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;
	REP(i, s.length()) {
		cnt[s[i] - 'A']++;
	}
	int now = 0;
	REP(i, s.length()) {
		if (firstt[s[i] - 'A'] == 0) {
			firstt[s[i] - 'A'] = 1;
			now++;
		}
		if (now > k) {
			cout << "YES" << endl;
			return 0;
		}
		cnt[s[i] - 'A']--;
		if (cnt[s[i] - 'A'] == 0) now--;
	}
	cout << "NO" << endl;
}