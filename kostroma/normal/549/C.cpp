#pragma comment (linker, "/STACK:128000000")
#define _CRT_SECURE_NO_WARNINGS
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

bool todo = true;

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
		//cout << "Case #" << testNum++ << ": ";
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

//#define int li

//int mod = 1000000007;

void print(int c) {
	if (c == 1) {
		printf("Daenerys");
	}
	else {
		printf("Stannis");
	}
	exit(0);
}

void solve() {
	int n, k;
	cin >> n >> k;
	vector<int> num(2, 0);
	for (int i = 0; i < n; ++i) {
		int cur;
		cin >> cur;
		++num[cur & 1];
	}

	k = n - k;
	
	if (k == 0) {
	    print(num[1] % 2 + 1);
	}
	
	if (k / 2 >= num[1]) {
		print(1);
	}

	if (k % 2 == 0) {
		if ((k + 1) / 2 >= num[0]) {
			if ((n - k) % 2)
				print(2);
			else
				print(1);
		}
		else {
			print(1);
		}
	}
	else {

		if ((k / 2) >= num[0] && (n - k) % 2 == 0) {
			print(1);
		}
		if ((n - k) % 2 && (k + 1) / 2 >= num[0]) {
			print(2);
		}

		print(2);
	}
	
}