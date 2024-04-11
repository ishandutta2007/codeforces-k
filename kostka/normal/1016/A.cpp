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

#ifdef ONLINE_JUDGE
#define FREOPEN(name) \
  freopen(name".in", "r", stdin); \
  freopen(name".out", "w", stdout);
#else
#define FREOPEN(name)
#endif

int main() {
  ios_base::sync_with_stdio(0);
  int n, m;
  cin >> n >> m;
  ll seen = 0;
  for(int i=0; i<n; i++) {
    int x;
    cin >> x;
    cout << (seen + x) / m - seen / m << " ";
    seen += x;
  }
  puts("");
  return 0;
}