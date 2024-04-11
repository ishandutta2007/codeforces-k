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

const int MAXN=300;

int n;
char s[MAXN+1];

char ans[2][MAXN+1];

bool solve() {
	if(n==2&&s[0]>=s[1]) return false;
	ans[0][0]=s[0],ans[0][1]='\0';
	REP(i,n-1) ans[1][i]=s[i+1]; ans[1][n-1]='\0';
	return true;
}

void run() {
	scanf("%d",&n);
	scanf("%s",s);
	if(!solve()) { printf("NO\n"); return; }
	printf("YES\n");
	printf("%d\n",2);
	printf("%s %s\n",ans[0],ans[1]);
}

int main() {
	int n; scanf("%d",&n); FORE(i,1,n) run();
	return 0;
}