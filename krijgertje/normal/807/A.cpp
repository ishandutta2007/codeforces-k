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

const int MAXN=1000;

int n;
int a[MAXN],b[MAXN];

void run() {
	scanf("%d",&n); REP(i,n) scanf("%d%d",&a[i],&b[i]);
	REP(i,n) if(a[i]!=b[i]) { printf("rated\n"); return; }
	int mn=a[0]; FOR(i,1,n) if(a[i]>mn) { printf("unrated\n"); return; } else if(a[i]<mn) mn=a[i];
	printf("maybe\n");
}

int main() {
	run();
	return 0;
}