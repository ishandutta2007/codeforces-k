#pragma comment(linker, "/STACK:1024000000")
#define _CRT_SECURE_NO_WARNINGS
#undef NDEBUG
//#include "testlib.h"
#include <cstdio>
#include <cassert>
#include <algorithm>
#include <iostream>
#include <memory.h>
#include <string>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <bitset>
#include <deque>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
#include <sstream>
#include <functional>
/*#ifndef room111
#include <sys/resource.h>
#endif*/
#include <unordered_set>
#include <unordered_map>
#include <array>
using namespace std;
#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve(bool);
void precalc();
clock_t start;
//int timer = 1;

int testNumber = 1;

bool todo = true;

bool stress = false;

int main() {
#ifdef room111
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	start = clock();
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	/*#ifndef room111
	const rlim_t kStackSize = 1024L * 1024L * 1024L;   // min stack size = 64 Mb
	struct rlimit rl;
	int result;

	result = getrlimit(RLIMIT_STACK, &rl);
	if (result == 0)
	{
	if (rl.rlim_cur < kStackSize)
	{
	rl.rlim_cur = kStackSize;
	result = setrlimit(RLIMIT_STACK, &rl);
	if (result != 0)
	{
	fprintf(stderr, "setrlimit returned result = %d\n", result);
	}
	}
	}
	#endif*/

	//cin >> t;
	int testNum = 1;
	while (t--) {
		//cerr << testNum << endl;
		//cout << "Case #" << testNum++ << ": ";
		solve(true);
		++testNumber;
		//++timer;
	}
#ifdef room1111
	while (true)
		solve(false);
#endif

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

/*int pr[] = { 97, 2011 };
int mods[] = { 1000000007, 1000000009 };

const int C = 300500;
int powers[2][C];*/

//int MOD = 1000000007;

//int c[5010][5010];

template<typename T>
T binpow(T q, T w, T mod) {
	if (!w)
		return 1 % mod;
	if (w & 1)
		return q * 1LL * binpow(q, w - 1, mod) % mod;
	return binpow(q * 1LL * q % mod, w / 2, mod);
}

/*int curMod = 1000000009;

int fact[100500], revfact[100500];

int getC(int n, int k) {
int res = fact[n] * revfact[n - k] % curMod * revfact[k] % curMod;
return res;
}*/

/*const int C = 7000500;

int least_prime[C];*/

void precalc() {

	/*for (int i = 2; i < C; ++i) {
	if (!least_prime[i]) {
	least_prime[i] = i;
	for (li j = i * 1LL * i; j < C; j += i) {
	least_prime[j] = i;
	}
	}
	}*/

	/*fact[0] = revfact[0] = 1;
	for (int i = 1; i < 100500; ++i) {
	fact[i] = fact[i - 1] * i % curMod;
	revfact[i] = binpow(fact[i], curMod - 2, curMod);
	}*/

	/*for (int w = 0; w < 2; ++w) {
	powers[w][0] = 1;
	for (int j = 1; j < C; ++j) {
	powers[w][j] = (powers[w][j - 1] * 1LL * pr[w]) % mods[w];
	}
	}*/
	/*for (int i = 0; i < 5010; ++i) {
	c[i][i] = c[i][0] = 1;
	for (int j = 1; j < i; ++j) {
	c[i][j] = (c[i - 1][j - 1] + c[i - 1][j]) % MOD;
	}
	}*/
}

template<typename T>
T gcd(T q, T w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}
template<typename T>
T lcm(T q, T w) {
	return q / gcd(q, w) * w;
}

//#define int li

//const int mod = 1000000007;

//int matrix[4][4] = { { 0, 1, 2, 3 }, { 5, 0, 7, 6 }, { 4, 8, 0, 2 }, { 7, 7, 7, 0 } }; //{ {0, 3, 2 },{5, 0, 7 },{ 4, 8, 0 } };

vector<vector<int>> matrix;

const int INF = 2e9;

int n;

vector<int> get_our(int l, int r) {
	vector<int> result(n, INF);
	for (int i = l; i < r; ++i) {
		for (int j = 0; j < n; ++j) {
			result[j] = min(result[j], matrix[j][i]);
		}
	}
	return result;
}

vector<int> get_result() {
	vector<int> res(n);
	for (int i = 0; i < n; ++i) {
		cin >> res[i];
	}
	return res;
}

int cnt = 0;
vector<int> get_query(const vector<int>& cur) {
	++cnt;
	//return get_our(l, r);
	cout << cur.size() << endl;
	for (int x : cur) {
		cout << x + 1 << " ";
	}
	cout << endl;
	return get_result();
}

const int L = 10;

void solve(bool read) {
	cin >> n;
	/*matrix.resize(n);
	for (int i = 0; i < n; ++i) {
		matrix[i].resize(n);
		for (int j = 0; j < n; ++j) {
			matrix[i][j] = rand();
			if (i == j) {
				matrix[i][j] = 0;
			}
		}
	}*/

	vector<vector<int>> questions(L * 2);
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < L; ++j) {
			if (i & (1 << j)) {
				questions[2 * j].push_back(i);
			}
			else {
				questions[2 * j + 1].push_back(i);
			}
		}
	}

	vector<vector<int>> ans(L * 2, vector<int>(n, INF));
	for (int i = 0; i < L * 2; ++i) {
		if (!questions[i].empty()) {
			ans[i] = get_query(questions[i]);
		}
	}

	cout << -1 << endl;
	for (int i = 0; i < n; ++i) {
		int res = INF;
		for (int j = 0; j < L; ++j) {
			if (i & (1 << j)) {
				res = min(res, ans[2 * j + 1][i]);
			}
			else {
				res = min(res, ans[2 * j][i]);
			}
		}
		cout << res << " ";
	}
	cout << endl;

	//cerr << "q = " << cnt << endl;

}