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

const int MAXN=500000;

typedef struct P { int l,r; } P;
bool operator<(const P &a,const P &b) { if(a.r!=b.r) return a.r<b.r; return a.l<b.l; }

P p[MAXN]; int n;


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&p[i].l,&p[i].r); sort(p,p+n);
	int ret=1,at=p[0].r+1;
	REP(i,n) if(p[i].l>=at) ++ret,at=p[i].r+1;
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}