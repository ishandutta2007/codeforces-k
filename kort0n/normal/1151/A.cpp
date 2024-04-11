#include <bits/stdc++.h>
#define endl "\n"
using namespace std;
typedef long long ll;
typedef pair<ll, ll> l_l;
typedef pair<int, int> i_i;
template<class T>
inline bool chmax(T &a, T b) {
    if(a < b) {
        a = b;
        return true;
    }
    return false;
}

template<class T>
inline bool chmin(T &a, T b) {
    if(a > b) {
        a = b;
        return true;
    }
    return false;
}

const long long INF = 1e18;
//const ll mod = 1000000007;
string ATGC = "ACTG";
int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N;
    cin >> N;
    string S;
    cin >> S;
    int ans = 1e9;
    for(int i = 0; i + 4 <= N; i++) {
        string T = S.substr(i, 4);
        int now = 0;
        for(int j = 0; j < 4; j++) {
            int tmp = abs(ATGC[j] - T[j]);
            chmin(tmp, abs(ATGC[j] - T[j] - 26));
            chmin(tmp, abs(ATGC[j] - T[j] + 26));
            now += tmp;
        }
        chmin(ans, now);
    }
    cout << ans << endl;
    return 0;
}