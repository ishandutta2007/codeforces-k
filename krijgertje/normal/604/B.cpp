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

int n,k;
int x[MAXN];

void run() {
	scanf("%d%d",&n,&k);
	REP(i,n) scanf("%d",&x[i]);
	int n2=max(0,n-k),n1=n-2*n2;
	int ret=0; REP(i,n2) ret=max(ret,x[i]+x[2*n2-1-i]); REP(i,n1) ret=max(ret,x[2*n2+i]); printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}