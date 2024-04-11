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

const int MAXN=100000;
const int MAXVAL=100000;

int n;
int a[MAXN];

int freq[MAXVAL+1]; int cnt;
bool seen[MAXVAL+1];


void run() {
	scanf("%d",&n); REP(i,n) scanf("%d",&a[i]);

	memset(freq,0,sizeof(freq)); cnt=0;
	memset(seen,false,sizeof(seen));
	REP(i,n) if(++freq[a[i]]==1) ++cnt;
	ll ret=0;
	REP(i,n) {
		if(--freq[a[i]]==0) --cnt;
		if(seen[a[i]]) continue;
		ret+=cnt,seen[a[i]]=true;
	}
	printf("%lld\n",ret);
}

int main() {
	run();
	return 0;
}