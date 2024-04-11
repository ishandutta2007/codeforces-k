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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

const int MAXN=1000;

int n;
int a[2*MAXN];

bool solve() {
	sort(a,a+2*n);
	ll lsum=0,rsum=0;
	REP(i,n) lsum+=a[i]; FOR(i,n,2*n) rsum+=a[i];
	return lsum!=rsum;
}

void run() {
	scanf("%d",&n);
	REP(i,2*n) scanf("%d",&a[i]);
	if(!solve()) { printf("-1\n"); return; }
	REP(i,2*n) { if(i!=0) printf(" "); printf("%d",a[i]); } puts("");

}

int main() {
	run();
	return 0;
}