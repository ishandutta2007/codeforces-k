//J^!w

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <utility>
#include <functional>
#include <cstring>
#include <queue>
#include <stack>
#include <math.h>
#include <iterator>
#include <vector>
#include <string>
#include <set>
#include <math.h>
#include <iostream>
#include <random>
#include<map>
#include <iomanip>
#include <time.h>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
#include <cassert>
#include<fstream>
#include <unordered_map>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <bitset>
using namespace std;
typedef string::const_iterator State;
#define Ma_PI 3.141592653589793
#define eps 1e-5
#define LONG_INF 2000000000000000000LL
#define GOLD 1.61803398874989484820458
#define MAX_MOD 1000000007LL
#define GYAKU 500000004LL
#define MOD 998244353LL
#define seg_size 262144*2
#define REP(a,b) for(long long a = 0;a < b;++a)
int grid[4][4] = {};
int main() {
	int xe[5] = { 1,0,-1,0 ,0};
	int ye[5] = { 0,-1,0,1 ,0};
	REP(i, 3) {
		REP(q, 3) {
			int a;
			cin >> a;
			if (a % 2 == 1) {
				for (int j = 0; j < 5; ++j) {
					int now_x = xe[j] + i;
					int now_y = ye[j] + q;
					if (now_x >= 0 && now_y >= 0) grid[now_x][now_y]++;
				}
			}
		}
	}
	REP(i, 3) {
		REP(q, 3) {
			cout << (grid[i][q]+1) % 2;
		}
		cout << endl;
	}
}