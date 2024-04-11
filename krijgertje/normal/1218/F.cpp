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
#include <cstring>
#include <list>  
#include <cassert>
#include <climits>
#include <bitset>
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
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n,shave;
int need[MAXN];
int drinkgain;
int cost[MAXN];

priority_queue<int> pq;

ll solve() {
	ll have=shave;
	ll ret=0;
	REP(i,n) {
		pq.push(-cost[i]);
		while(!pq.empty()&&have<need[i]) { int cur=-pq.top(); pq.pop(); ret+=cur; have+=drinkgain; }
		if(have<need[i]) return -1;
	}
	return ret;
}

void run() {
	scanf("%d%d",&n,&shave);
	REP(i,n) scanf("%d",&need[i]);
	scanf("%d",&drinkgain);
	REP(i,n) scanf("%d",&cost[i]);
	printf("%lld\n",solve());
}

int main() {
	run();
	return 0;
}