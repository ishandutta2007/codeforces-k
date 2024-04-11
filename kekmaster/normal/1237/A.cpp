#ifndef LOCAL
#pragma GCC optimize("O3")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,tune=native")
#endif
#include <bits/stdc++.h>
#ifdef LOCAL
#include "template.h"
#endif

using namespace std;
#ifndef LOCAL
#define dbg(...) (void)0
#define ARR(arr, ...) (void)0
#define eprintf(...) (void)0
#endif

#define mp make_pair
#define rand govno_ebanoe
#define dbg_time() eprintf("\n\nTime: %.3lf\n", double(clock()) / CLOCKS_PER_SEC)

using ll = long long;
using pii = pair<int, int>;
using dbl = double;

const int N = 14000;
int n;
int a[N];

void solve() {
    scanf("%d", &n);
    bool up = false;
    for(int i = 0; i < n; ++i) {
        scanf("%d", &a[i]);
        if (a[i] % 2 == 0)
            a[i] /= 2;
        else {
            if (a[i] > 0) {
                if (up)
                    a[i] = (a[i] + 1) / 2;
                else
                    a[i] = a[i] / 2;
                up = !up;
            } else {
                if (up)
                    a[i] = -(abs(a[i]) / 2);
                else
                    a[i] = -((abs(a[i]) + 1) / 2);
                up = !up;
            }
        }
    }
    for(int i = 0; i < n; ++i)
        printf("%d\n", a[i]);
}

int main() {
#ifndef LOCAL
	//freopen("sum.in", "r", stdin);
	//freopen("sum.out", "w", stdout);
#endif

		int test_count = 1;
#ifdef MULTITEST
		scanf("%d", &test_count);
		char endl1[5];
		fgets(endl1, 5, stdin);
#endif
		for (int i = 0; i < test_count; ++i) {
#ifdef CASES
			printf("Case #%d: ", i + 1);
			solve();
			eprintf("Passed case #%d:\n", i + 1);
#else
			solve();
#endif
		}
	dbg_time();
    return 0;
}