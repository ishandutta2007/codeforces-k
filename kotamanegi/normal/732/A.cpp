#define _CRT_SECURE_NO_WARNINGS
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
#include<map>
#include <iomanip>
#include <stdlib.h>
#include <list>
#include <typeinfo>
#include <list>
#include <set>
using namespace std;
#define MAX_MOD 1000000007
#define REP(i,n) for(long long i = 0;i < n;++i)
#define LONGINF 1000000000000000000
int main() {
	ios::sync_with_stdio(false);
	int k, r;
	cin >> k >> r;
	int ans = 0;
	for (int i = 1;i != 0;++i) {
		ans += k;
		if (ans % 10 == r||ans%10 == 0) {
			cout << i << endl;
			return 0;
		}
	}
}