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

const int MAXN=100;

int n,lim;
int a[MAXN];

int l[MAXN],r[MAXN];

int solve() {
	REP(i,n) l[i]=max(1,a[i]-lim),r[i]=a[i]+lim;
	int mxl=l[0],mnr=r[0]; FOR(i,1,n) mxl=max(mxl,l[i]),mnr=min(mnr,r[i]);
	return mxl<=mnr?mnr:-1;
}

void run() {
	scanf("%d%d",&n,&lim);
	REP(i,n) scanf("%d",&a[i]);
	printf("%d\n",solve());
}

int main() {
	int ncases; scanf("%d",&ncases); FORE(i,1,ncases) run();
	return 0;
}