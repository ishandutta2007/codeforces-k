#pragma comment (linker, "/STACK:526000000")
#define  _CRT_SECURE_NO_WARNINGS
#include "bits/stdc++.h"

using namespace std;
typedef string::const_iterator State;
#define eps 1e-11L
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL

#define MOD 998244353LL
#define seg_size 262144
#define pb push_back
#define mp make_pair
typedef long long ll;
#define REP(a,b) for(long long (a) = 0;(a) < (b);++(a))
#define ALL(x) (x).begin(),(x).end()
unsigned long xor128() {
    static unsigned long x = 123456789, y = 362436069, z = 521288629, w = 88675123;
    unsigned long t = (x ^ (x << 11));
    x = y; y = z; z = w;
    return (w = (w ^ (w >> 19)) ^ (t ^ (t >> 8)));
}
void init() {
    iostream::sync_with_stdio(false);
    cout << fixed << setprecision(100);
}
#define int ll
int gcd(int a, int b) {
    if (b == 0) return a;
    return gcd(b, a % b);
}
void solve(){
    int n;
    cin >> n;
    map<long long, long long> now;
    REP(i, n*n) {
        long long a;
        cin >> a;
        now[-a]++;
    }
    vector<long long> ans;
    for (auto x = now.begin(); x != now.end(); ++x) {
        while (x->second != 0) {
            ans.push_back(-(x->first));
            for (int q = 0; q < ans.size()-1; ++q) {
                now[-gcd(ans[q], ans.back())] -= 2;
            }
            now[(x->first)]--;
        }
    }
    REP(i, ans.size()) {
        cout << ans[i] << " ";
    }
    cout << endl;
}
#undef int
int main() {
    init();
    solve();
}