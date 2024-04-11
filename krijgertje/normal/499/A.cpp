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
int gcd(int a,int b) { return b==0?a:gcd(b,a%b); }

int nscenes,nskip;
int l[50],r[50];



void run() {
	scanf("%d%d",&nscenes,&nskip);
	REP(i,nscenes) scanf("%d%d",&l[i],&r[i]);
	int atmin=1,atscene=0,ret=0;
	while(atscene<nscenes) {
		if(atmin>r[atscene]) { ++atscene; continue; }
		if(atmin+nskip<=l[atscene]) { atmin+=nskip; continue; }
		++atmin; ++ret;
	}
	printf("%d\n",ret);
}

int main() {
	run();
	return 0;
}