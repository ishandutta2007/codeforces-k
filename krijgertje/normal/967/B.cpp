#include <algorithm>  
#include <iostream>  
#include <sstream>  
#include <string>  
#include <cstring>
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
#include <ctime>
#include <climits>
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
typedef unsigned long long ull;
ll gcd(ll a,ll b) { return b==0?a:gcd(b,a%b); }

const int MAXN=100000;

int n,mx,need;
int s[MAXN];

int solve() {
	sort(s+1,s+n);
	int ssum=0; REP(i,n) ssum+=s[i];
	for(int i=n-1;i>=0;--i) {
		if((ll)s[0]*mx>=(ll)need*ssum) return n-i-1;
		ssum-=s[i];
	}
	assert(false); return -1;
}

void run() {
	scanf("%d%d%d",&n,&mx,&need); REP(i,n) scanf("%d",&s[i]);
	printf("%d\n",solve());
}

int main() {
	run();
	return 0;
}