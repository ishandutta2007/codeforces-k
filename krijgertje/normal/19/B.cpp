#include <algorithm> 
#include <iostream> 
#include <sstream> 
#include <string> 
#include <vector> 
#include <queue> 
#include <set> 
#include <map> 
#include <cstdio> 
#include <cstdlib> 
#include <cctype> 
#include <cmath> 
#include <list>
#include <cassert>
#include <climits>
#include <cstring>
using namespace std; 

#define PB push_back 
#define MP make_pair 
#define SZ(v) ((int)(v).size()) 
#define FOR(i,a,b) for(int i=(a);i<(b);++i) 
#define REP(i,n) FOR(i,0,n) 
#define FORE(i,a,b) for(int i=(a);i<=(b);++i) 
#define REPE(i,n) FORE(i,0,n) 
#define FORSZ(i,a,v) FOR(i,a,SZ(v)) 
#define REPSZ(i,v) REP(i,SZ(v)) 
typedef long long ll;
typedef vector<int> VI; typedef vector<VI> VVI; typedef vector<VVI> VVVI;

void run() {
	int n; scanf("%d",&n);
	vector<int> time(n),price(n); REP(i,n) scanf("%d%d",&time[i],&price[i]);
	vector<ll> dp(n+1,LLONG_MAX); dp[n]=0;
	REP(i,n) {
		FORE(at,1,n) if(dp[at]!=LLONG_MAX) {
			int to=max(0,at-1-time[i]);
			ll ncost=dp[at]+price[i];
			if(ncost<dp[to]) dp[to]=ncost;
		}
	}
	cout<<dp[0]<<endl;
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}