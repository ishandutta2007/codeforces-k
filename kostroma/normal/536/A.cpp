#pragma comment (linker, "/STACK:128000000")
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
//#include <unordered_map>
//#include <unordered_set>
#include <ctime>
#include <stack>
#include <queue>
#include <fstream>
using namespace std;
//#define FILENAME ""
#define mp make_pair
#define all(a) a.begin(), a.end()
typedef long long li;
typedef long double ld;
void solve();
void precalc();
clock_t start;
//int timer = 1;

bool doing = true;

int main() {
#ifdef room111
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
#else
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	//freopen(FILENAME".in", "r", stdin);
	//freopen(FILENAME ".out", "w", stdout);
#endif
	int t = 1;
	cout.sync_with_stdio(0);
	cin.tie(0);
	precalc();
	cout.precision(10);
	cout << fixed;
	//cin >> t;
	start = clock();
	int testNum = 1;
	while (t--) {
		//cout << "Case #" << testNum++ << ":\n";
		solve();
		//++timer;
	}

#ifdef room111
	cerr << "\n\n" << (clock() - start) / 1.0 / CLOCKS_PER_SEC << "\n\n";
#endif

	return 0;
}

//BE CAREFUL: IS INT REALLY INT?

//#define int li

void precalc() {

}

int binpow(int q, int w, int mod) {
	if (!w)
		return 1;
	if (w & 1)
		return q * binpow(q, w - 1, mod) % mod;
	return binpow(q * q % mod, w / 2, mod);
}

int gcd(int q, int w) {
	while (w) {
		q %= w;
		swap(q, w);
	}
	return q;
}

#define int li

//int mod = 1000000007;


void solve() {
	int a, b, n;
	cin >> a >> b >> n;
	for (int w = 0; w < n; ++w) {
		int l, t, m;
		cin >> l >> t >> m;
		int A = a + (l - 1) * b;
		int B = b;

		int L = -1, R = 3e6 / sqrt(1.0 * B) + 10;
		while (L + 1 < R) {
			int M = (L + R) / 2;

			int res;

			int mx = A + M * B;
			int sum = A * M + B * M * (M - 1) / 2;

			if (m == 1) {
				res = mx + sum;
			}
			else {
				if (m >= M + 1) {
					res = mx;
				}
				else {

					if (sum < mx * (m - 1)) {
						res = mx;
					}
					else {
						res = (sum + mx - 1) / m + 1;
					}
				}
			}
			if (res <= t) {
				L = M;
			}
			else {
				R = M;
			}

		}

		if (L != -1) {
			L += l;
		}

		cout << L << "\n";

	}
}