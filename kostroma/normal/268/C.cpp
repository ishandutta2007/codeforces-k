#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <queue>
#include <deque>
#include <cmath>
#include <ctime>
#include <stack>
#include <set>
#include <map>
#include <cassert>
#include <memory.h>

using namespace std;

#define mp make_pair
#define pb push_back
#define all(a) a.begin(), a.end()

typedef long long li;
typedef long double ld;
typedef vector<int> vi;
typedef pair <int, int> pi;

void solve();
void precalc();
#define FILENAME "change me please"
int main(){
	string s = FILENAME;
#ifdef room210
	freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	//cout<<FILENAME<<endl;
	//assert (s != "change me please");
	clock_t start = clock();
#else
	//freopen(FILENAME ".in", "r", stdin);
	//freopen(FILENAME".out", "w", stdout);
#endif
	//cout.sync_with_stdio(0);
	int t = 1;
	//precalc();
	//cout << "done!\n";
	//cin >> t;
	//gen();
	while (t--)
		solve();
#ifdef room210
	cout<<"\n\n\n"<<(clock() - start) / 1.0 / CLOCKS_PER_SEC<<"\n\n\n";
#endif
	return 0;
}

//#define int li


void solve(){
	int n, m;
	cin >> n >> m;
	cout << min(n, m) + 1 << endl;
	if (n > m)
		swap(n, m);
	for (int i = 0; i <= n && i <= m; ++i) {
		cout << n - i << ' ' << i << endl;
	}
}