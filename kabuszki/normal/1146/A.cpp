#include<bits/stdc++.h>
using namespace std;

#define int long long

#define FOR(i,a,b) for(int i=(a);i<=(b);i++)
#define REP(i,a) FOR(i,0,(a)-1)
#define SIZE(v) (int)(v).size()
#define PB push_back
#define EB emplace_back
#define IN insert
#define ER erase
#define ALL(a) (a).begin(),(a).end()
#define ST first
#define ND second

typedef vector<int> VI;
typedef pair<int, int> PII;
typedef vector<PII> VII;


void jebaj() {
    string s;
    cin >> s;
    int n = SIZE(s);
    int as = 0;
    for (auto c : s) as += (c == 'a');
    while (as * 2 <= n) {
        n--;
    }
    cout << n << "\n";
}

#undef int

int main() {

    #define int long long
    int t = 1;
    while (t--) {
        jebaj();
    }
    return 0;
}