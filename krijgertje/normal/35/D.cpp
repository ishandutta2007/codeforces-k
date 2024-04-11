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
#include <stack>
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
	freopen ("input.txt","r",stdin);
	freopen ("output.txt","w",stdout);

	int n,cap; scanf("%d%d",&n,&cap);
	vector<int> x; REP(i,n) { int y; scanf("%d",&y); x.PB(y*(n-i)); }
	sort(x.begin(),x.end());
//	REPSZ(i,x) printf("%d\n",x[i]);
	
	int left=cap,ret=0;
	REP(i,n) if(x[i]<=left) left-=x[i],++ret;
	printf("%d\n",ret);
}

int main() {
//	int n; scanf("%d",&n); REP(i,n)
	run();
	return 0;
}