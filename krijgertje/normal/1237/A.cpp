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

const int MAXN=13845;

int n;
int a[MAXN];
int b[MAXN];

int divdn(int num,int den) { return num>=0?num/den:(num-den+1)/den; }
int divup(int num,int den) { return num>=0?(num+den-1)/den:num/den; }

void solve() {
	bool moreup=false;
	REP(i,n) {
		if(a[i]%2==0) { b[i]=a[i]/2; continue; }
		if(moreup) { b[i]=divdn(a[i],2); moreup=false; } else { b[i]=divup(a[i],2); moreup=true; }
	}
}

void run() {
	scanf("%d",&n);
	REP(i,n) scanf("%d",&a[i]);
	solve();
	REP(i,n) printf("%d\n",b[i]);
}

int main() {
	run();
	return 0;
}