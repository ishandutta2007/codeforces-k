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
typedef struct P { int x,d; } P;
bool operator<(const P &a,const P &b) { return a.x<b.x; }

int n;
P p[MAXN];
int dp[MAXN];

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d%d",&p[i].x,&p[i].d);
	sort(p,p+n);

	REP(i,n) {
		int l=-1,h=i; // [l,h) first beacon with x < p[i].x-p[i].d
		while(l+1<h) {
			int m=l+(h-l)/2;
			if(p[m].x<p[i].x-p[i].d) l=m; else h=m;
		}
		dp[i]=(l==-1?0:dp[l])+(i-l-1);
	}
	int ret=n;
	REP(i,n) { int cur=dp[i]+(n-i-1); if(cur<ret) ret=cur; }
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}