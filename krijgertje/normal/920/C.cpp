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

const int MAXN=2000000;

int n;
int a[MAXN];
char can[MAXN-1+1];

bool solve() {
	int lst=-1;
	for(int l=0,r=l;l<n;l=r) {
		while(can[r]=='1') ++r; ++r;
		int mn=INT_MAX,mx=INT_MIN;
		FOR(i,l,r) mn=min(mn,a[i]),mx=max(mx,a[i]);
		//printf("%d..%d: mn=%d mx=%d\n",l,r,mn,mx);
		if(mn<lst) return false; lst=mx;
	}
	return true;
}

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]); scanf("%s",can);
	printf("%s\n",solve()?"YES":"NO");
}

int main() {
	run();
	return 0;
}