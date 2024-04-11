#pragma GCC optimize("O2,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) x.begin(), x.end()
using ll = long long;
#define int ll
using namespace std;
const int maxn = 1<<19;
const int inf = 1e18;
int32_t main() {
	ios::sync_with_stdio(0);
	int t;
	cin >> t;
	while(t--) {
		int n;
		cin >> n;
		vector<int> a(n);
		for(auto &i : a) cin >> i;
		set<int> b(all(a));
		if(b.size() == 1) {cout << "-1\n";continue;}
		int f = *b.rbegin();
		int i = 0;
		while(1) {
			if(a[i] != f) {i++;continue;}
			if((!i || a[i-1] == f) && (i+1==n||a[i+1]==f)) {i++;continue;}
			break;
		}
		cout << ++i << '\n';
	}
	return 0;
}