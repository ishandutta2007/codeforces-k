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

const int MAXN=100;

int n;
char s[MAXN+1];
int cnt[26*26];

void run() {
	scanf("%d",&n); scanf("%s",s);
	memset(cnt,0,sizeof(cnt));
	REP(i,n-1) { int x=s[i]-'A',y=s[i+1]-'A'; ++cnt[x*26+y]; }
	int mxi=0; REP(i,26*26) if(cnt[i]>cnt[mxi]) mxi=i;
	printf("%c%c\n",'A'+mxi/26,'A'+mxi%26);
}

int main() {
	run();
	return 0;
}