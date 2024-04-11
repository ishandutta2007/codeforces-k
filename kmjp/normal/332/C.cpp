#include <cstdlib>
#include <cstring>
#include <memory>
#include <cstdio>
#include <fstream>
#include <iostream>
#include <cmath>
#include <string>
#include <sstream>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <algorithm>
using namespace std;

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <unistd.h>

typedef signed long long ll;
typedef unsigned long long u64;

#define _PE(...) printf(__VA_ARGS__); fprintf(stderr, __VA_ARGS__);
#define _E(...) fprintf(stderr, __VA_ARGS__)
#undef _P
#define _P(...) printf(__VA_ARGS__)

#define FOR(x,to) for(x=0;x<to;x++)
#define FOR2(x,from,to) for(x=from;x<to;x++)
#define ITR(x,c) for(__typeof(c.begin()) x=c.begin();x!=c.end();x++)
#define ZERO(a) memset(a,0,sizeof(a))
void _fill_int(int* p,int val,int rep) {int i;  FOR(i,rep) p[i]=val;}
#define FILL_INT(a,val) _fill_int((int*)a,val,sizeof(a)/4)
#define ZERO2(a,b) memset(a,0,b)
#define MINUS(a) _fill_int((int*)a,-1,sizeof(a)/4)
#define GETs(x) scanf("%s",x);
int GETi() { int i;scanf("%d",&i); return i;}
#define GET1(x) scanf("%d",x);
#define GET2(x,y) scanf("%d%d",x,y);
#define GET3(x,y,z) scanf("%d%d%d",x,y,z);

#define EPS (1e-11)
template <class T> T sqr(T val){ return val*val;}

//-------------------------------------------------------

int N,P,K;
pair<pair<int,int>, int> V[100001];
pair<pair<int,int>, pair<int,int> > V2[100001];

void solve() {
    int f,r,i,j,k,l,x,y,tx,ty;
    
    cin >> N >> P >> K;
    FOR(i,N) {
        cin>>x>>y;
        V[i]=make_pair(make_pair(y,-x),i+1);
    }
    sort(V,V+N);
    //FOR(i,N) _P("%d:a%d b%d %d\n",i,-V[i].first.second,V[i].first.first,V[i].second);
    FOR(i,N-(P-K)) {
        V2[i].first = make_pair(-V[i+(P-K)].first.second,V[i+(P-K)].first.first);
        V2[i].second = make_pair((P-K)+i,V[i+(P-K)].second);
    }
    sort(V2,V2+N-(P-K));
    //FOR(i,N-(P-K)) _P("%d:a%d b%d %d %d\n",i,V2[i].first.first,V2[i].first.second,V2[i].second.first,V2[i].second.second);
    
    int mi=N;
    FOR(i,K) {
        _P("%d ",V2[N-(P-K)-1-i].second.second);
        mi = min(mi, V2[N-(P-K)-1-i].second.first);
    }
    //_P("[[%d\n",mi);
    
    FOR(i,(P-K)) _P("%d ",V[--mi].second);
    _P("\n");
    
    return;
}


int main(int argc,char** argv){
    
    if(argc>1) freopen(argv[1], "r", stdin);
    solve();
    return 0;
}