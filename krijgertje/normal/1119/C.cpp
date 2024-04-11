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

const int MAXH=500;
const int MAXW=500;

int h,w;
int a[MAXH][MAXW];
int b[MAXH][MAXW];

int c[MAXH][MAXW];

bool solve() {
	REP(x,h) REP(y,w) c[x][y]=a[x][y]^b[x][y];
	REP(x,h) REP(y,w) if(x!=0&&y!=0&&c[x][y]!=0) { c[x][y]^=1; c[x][0]^=1; c[0][y]^=1; c[0][0]^=1; }
	REP(x,h) REP(y,w) if(c[x][y]!=0) return false;
	return true;
}

void run() {
	scanf("%d%d",&h,&w);
	REP(x,h) REP(y,w) scanf("%d",&a[x][y]);
	REP(x,h) REP(y,w) scanf("%d",&b[x][y]);
	printf("%s\n",solve()?"Yes":"No");
}

int main() {
	run();
	return 0;
}