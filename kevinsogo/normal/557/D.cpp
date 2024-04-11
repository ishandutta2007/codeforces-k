#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <time.h>
#define fo(i,a,b) dfo(int,i,a,b)
#define fr(i,n) dfr(int,i,n)
#define fe(i,a,b) dfe(int,i,a,b)
#define fq(i,n) dfq(int,i,n)
#define nfo(i,a,b) dfo(,i,a,b)
#define nfr(i,n) dfr(,i,n)
#define nfe(i,a,b) dfe(,i,a,b)
#define nfq(i,n) dfq(,i,n)
#define dfo(d,i,a,b) for (d i = (a); i < (b); i++)
#define dfr(d,i,n) dfo(d,i,0,n)
#define dfe(d,i,a,b) for (d i = (a); i <= (b); i++)
#define dfq(d,i,n) dfe(d,i,1,n)
#define ffo(i,a,b) dffo(int,i,a,b)
#define ffr(i,n) dffr(int,i,n)
#define ffe(i,a,b) dffe(int,i,a,b)
#define ffq(i,n) dffq(int,i,n)
#define nffo(i,a,b) dffo(,i,a,b)
#define nffr(i,n) dffr(,i,n)
#define nffe(i,a,b) dffe(,i,a,b)
#define nffq(i,n) dffq(,i,n)
#define dffo(d,i,a,b) for (d i = (b)-1; i >= (a); i--)
#define dffr(d,i,n) dffo(d,i,0,n)
#define dffe(d,i,a,b) for (d i = (b); i >= (a); i--)
#define dffq(d,i,n) dffe(d,i,1,n)
#define ll long long
#define alok(n,t) ((t*)malloc((n)*sizeof(t)))
#define pf printf
#define sf scanf
#define pln pf("\n")
#define flsh fflush(stdout)
#include <map>
#include <algorithm>
#include <vector>
#include <set>
#include <iostream>
using namespace std;

#define LIM 100011

vector<vector<int> > adj(LIM);

int color[LIM];
int queue[LIM];

int main() {
	int n, e;
	sf("%d%d", &n, &e);
	fr(i,e) {
		int a, b;
		sf("%d%d", &a, &b);
		a--,b--;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	fr(i,n) {
		color[i] = 0;
	}
	ll singletons = 0;
	ll pairs = 0;
	ll defans = 0;
	bool has_big = false;
	bool has_cycle = false;
	fr(i,n) {
		if (!color[i]) {
			int q = 0;
			queue[q++] = i;
			color[i] = 1;
			ll c1 = 1, c2 = 0;
			fr(f,q) {
				int ci = queue[f];
				fr(nb,adj[ci].size()) {
					int cj = adj[ci][nb];
					if (!color[cj]) {
						color[cj] = 3 - color[ci];
						(color[cj] == 1 ? c1 : c2)++;
						queue[q++] = cj;
					} else if (color[ci] == color[cj]) {
						has_cycle = true;
						break;
					}
				}
			}
			if(has_cycle) break;
			if (q == 1) {
				singletons++;
			} else if (q == 2) {
				pairs++;
			} else {
				defans += c1 * (c1-1)>>1;
				defans += c2 * (c2-1)>>1;
				has_big = true;
			}
		}
	}
	if (has_cycle) {
		pf("0 1\n");
	} else if (has_big) {
		pf("1 %I64d\n", defans);
	} else if (pairs) {
		pf("2 %I64d\n", pairs * (n-2));
	} else {
		pf("3 %I64d\n", singletons * (singletons-1) * (singletons-2) / 6);
	}
}