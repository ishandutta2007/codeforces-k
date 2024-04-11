//Bartek Kostka
//  You are not prepared!

#include "bits/stdc++.h"

using namespace std;

#define x first
#define y second
#define SZ(x) int(x.size())
#define ll long long
#define pii pair <int, int>
#define vi vector <int>
#define ALL(x) x.begin(), x.end()

#ifdef LOCAL
template<class TH> void _dbg(const char *sdbg, TH h){ cerr<<sdbg<<" = "<<h<<endl; }
template<class TH, class... TA> void _dbg(const char *sdbg, TH h, TA... a) {
  while(*sdbg!=',')cerr<<*sdbg++;
  cerr<<" = "<<h<<", "; _dbg(sdbg+1, a...);
}
#define dbg(...) _dbg(#__VA_ARGS__, __VA_ARGS__)
#else
#define dbg(...)
#define cerr if(false) cout
#endif

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  string x;
  cin >> x;
  int n = SZ(x);
  vi ret(n);
  for(int i=1; i<n; i++) {
    if(x[i] == 'a') {
      ret[i] ^= 1;
      ret[i-1] ^= 1;
    }
  }
  for(int i=0; i<n; i++) cout << ret[i] << " ";
  cout << "\n";
  #ifdef LOCAL
    string s = x;
    for(int i=0; i<n; i++) {
      if(ret[i]) reverse(s.begin(), s.begin()+i+1);
    }
    string c = x;
    sort(ALL(c));
    assert(c == s);
  #endif
  return 0;
}